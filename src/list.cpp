/* 
 * File:   list.cpp
 * Author: Abdelrahman Abdelhamed
 * 
 * Created on March 9, 2017
 */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#include "../include/list.h"
#include "../include/node.h"

List::List() {
    this->pFirstNode = NULL;
    this->pLastNode = NULL;
}

List::List(Node *pFirstNode, Node *pLastNode) {
    this->pFirstNode = pFirstNode;
    this->pLastNode = pLastNode;
}

List::~List() {
    delete this->pFirstNode;
    delete this->pLastNode;
}

void List::operator=(const List &list) {
    this->pFirstNode = list.getFirstNode();
    this->pLastNode = list.getLastNode();
}

void List::printList() {

    Node *currentNode = this->getFirstNode()->getNext();

    cout << "name" << "\t\t" << "parent's name" << "\t\t" << "cost" << endl;

    cout << this->getFirstNode()->getName() << "\t\t" << '-' << "\t\t\t" << this->getFirstNode()->getCost() << endl;
    while (currentNode != NULL) {
        cout << currentNode->getName() << "\t\t" << currentNode->getParent()->getName() << "\t\t\t" << currentNode->getCost() << endl;
        currentNode = currentNode->getNext();
    }
}

void List::printResult() {
    string solutionPath = " ";

    float solutionCost = 0.0;
    int numberOfNodesExpanded = 0;

    Node *goalNode = this->getFirstNode();
    Node *currentNode = this->getFirstNode()->getNext();

    cout << endl;
    while (currentNode != NULL) {
        if (currentNode->isExplored()) {
            numberOfNodesExpanded++;
            goalNode = currentNode;
        }
        currentNode = currentNode->getNext();
    }

    solutionPath += goalNode->getName();
    solutionPath += " ";

    Node *resultNode = goalNode->getParent();
    while (resultNode != NULL) {
        solutionPath += resultNode->getName();
        solutionPath += " ";

        resultNode = resultNode->getParent();
    }
    reverse(solutionPath.begin(), solutionPath.end());

    cout << "Solution Path = " << solutionPath << endl << endl;
    cout << "Solution Cost = " << goalNode->getCost() << endl << endl;
    cout << "Number Of Nodes Expanded = " << numberOfNodesExpanded << endl << endl;

    if (goalNode->getCost() == 0.0)
        cout << endl << "Note: Cost has been neglected (cost = 0) due to the use of Depth First or Breadth First algorithms." << endl << endl;
}

Node* List::getFirstNode() const {
    return this->pFirstNode;
}

Node* List::getLastNode() const {
    return this->pLastNode;
}

void List::setFirstNode(Node *pFirstNode) {
    this->pFirstNode = pFirstNode;
}

void List::setLastNode(Node *pLastNode) {
    this->pLastNode = pLastNode;
}