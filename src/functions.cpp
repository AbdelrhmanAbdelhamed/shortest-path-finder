/* 
 * File:   functions.cpp
 * Author: Abdelrahman Abdelhamed
 * 
 * Created on March 5, 2017
 */

#include <vector>
#include <iostream>


#include "../include/functions.h"
#include "../include/link.h"

using namespace std;

void acquireLinks(vector<Link> &links, map<char, float> &heuristics) {
    char city1 = ' ';
    char city2 = ' ';
    float linkCost = 0.0;

    cout << endl << endl << "Please enter your links in the following format:- '{city1} {city2} {linkCost}';" << endl;
    cout << "(enter '.' in either cities or a negative linkCost number to stop the acquisition process) " << endl << endl;
    while (true) {

        cin >> city1;
        city1 = toupper(city1);

        cin >> city2;
        city2 = toupper(city2);

        cin >> linkCost;

        if (city1 == '.' || city2 == '.' || linkCost < 0.0) {
            return;
        } else {
            heuristics[city1] = 0.0;
            heuristics[city2] = 0.0;

            Link link = Link(city1, city2, linkCost); // Wrapping the input into a link object.
            links.push_back(link); // Filling the vector (Adding new Link).
        }
    }

}

void acquireHuristics(map<char, float> &heuristics) {
    cout << endl << "Please enter additional information for each requested node. (Heuristics)." << endl;

    for (auto it = heuristics.begin(); it != heuristics.end(); ++it) {
        char city = it->first;
        float heuristic;

        cout << endl << "Heuristic(" << city << ") = ";
        cin >> heuristic;

        heuristics[city] = heuristic;
    }
}