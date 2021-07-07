/* 
 * File:   main.cpp
 * Author: Abdelrahman Abdelhamed
 *
 * Created on March 5, 2017
 */

#include <iostream>
#include <vector>
#include <map>

#include "../include/searchAlgorithm.h"
#include "../include/link.h"
#include "../include/functions.h"
#include "../include/node.h"
#include "../include/list.h"

using namespace std;

int main(int argc, char** argv) {
    int userInput; // input for The search algorithm number.
    SEARCH_ALGORITHM searchAlgorithm; // The search algorithm instance based on userInput.

    vector<Link> links;
    char startCity, goalCity;

    map<char, float> heuristics;

    Node *pStartCity;
    Node *pCurrentCity;

    List *pFrontier;

    do {
        cout << "========================================================================" << endl << endl;

        cout << "#" << static_cast<int> (SEARCH_ALGORITHM::DEPTH_FIRST) << "- Depth First " << endl << endl;
        cout << "#" << static_cast<int> (SEARCH_ALGORITHM::BREADTH_FIRST) << "- Breadth First " << endl << endl;
        cout << "#" << static_cast<int> (SEARCH_ALGORITHM::UNIFORM_COST) << "- Uniform Cost " << endl << endl;
        cout << "#" << static_cast<int> (SEARCH_ALGORITHM::GREEDY) << "- Greedy " << endl << endl;
        cout << "#" << static_cast<int> (SEARCH_ALGORITHM::A_STAR) << "- A* (A Star) " << endl << endl;

        cout << "Please enter the number of the search algorithm you want to use. (Enter '0' or 'Negative Number' to terminate):- ";
        cin >> userInput;

        if (userInput > 0 && userInput < 6)
            searchAlgorithm = static_cast<SEARCH_ALGORITHM> (userInput);
        else if (userInput > 5)
            continue;
        else
            exit(0);

        acquireLinks(links, heuristics);

        cout << endl << "Please enter your start city: ";
        cin >> startCity;

        cout << endl << "Please enter your destination/goal city: ";
        cin >> goalCity;

        startCity = toupper(startCity);
        goalCity = toupper(goalCity);

        if ((searchAlgorithm == SEARCH_ALGORITHM::GREEDY) || (searchAlgorithm == SEARCH_ALGORITHM::A_STAR)) {
            acquireHuristics(heuristics);
        }
        
        cout << endl << endl;

        pStartCity = new Node(startCity, NULL, NULL, 0.0, true);
        pFrontier = new List(pStartCity, pStartCity);

        pCurrentCity = pFrontier->getFirstNode();
        while (!pCurrentCity->isGoal(goalCity)) {
            pCurrentCity->expand(links, pFrontier, searchAlgorithm);

            pCurrentCity = pCurrentCity->findNextNodeToBeExplored(heuristics,
                    [searchAlgorithm] (const Node *nextNode, const Node *toBeExploredNode, map<char, float> &heuristics) -> bool {

                        float firstCostOperand;
                        float secondCostOperand;

                        if ((searchAlgorithm == SEARCH_ALGORITHM::BREADTH_FIRST) || (searchAlgorithm == SEARCH_ALGORITHM::DEPTH_FIRST)) {
                            /** Always return false to pick the next node in the frontier list no matter what.
                            *  Now every node is the same in term of cost.
                            */
                            return false;

                        } else if (searchAlgorithm == SEARCH_ALGORITHM::UNIFORM_COST) {
                            firstCostOperand = nextNode->getCost();
                            secondCostOperand = toBeExploredNode->getCost();

                        } else if (searchAlgorithm == SEARCH_ALGORITHM::GREEDY) {
                            firstCostOperand = heuristics[ nextNode->getName() ];
                            secondCostOperand = heuristics[ toBeExploredNode->getName() ];

                        } else if (searchAlgorithm == SEARCH_ALGORITHM::A_STAR) {
                            firstCostOperand = nextNode->getCost() + heuristics[ nextNode->getName() ];
                            secondCostOperand = toBeExploredNode->getCost() + heuristics[ toBeExploredNode->getName() ];
                        }
                        return firstCostOperand < secondCostOperand;
                    }
            );
            pCurrentCity->setExplored(true);
        }

        pFrontier->printList();
        pFrontier->printResult();

        cout << "========================================================================" << endl << endl;

    } while (true);
}