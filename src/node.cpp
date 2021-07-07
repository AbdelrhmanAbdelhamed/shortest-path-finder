/* 
 * File:   node.cpp
 * Author: Abdelrahman Abdelhamed
 * 
 * Created on March 5, 2017
 */

#include <iostream>
#include <vector>
#include <map>
#include <functional>   

using namespace std;

#include "../include/searchAlgorithm.h"
#include "../include/node.h"
#include "../include/link.h"
#include "../include/list.h"

Node::Node() {
    this->name = ' ';
    this->pParent = NULL;
    this->pNext = NULL;
    this->cost = 0.0;
    this->explored = false;
}

Node::Node(char name, Node* pParent, Node* pNext, float cost, bool explored) {
    this->name = name;
    this->pParent = pParent;
    this->pNext = pNext;
    this->cost = cost;
    this->explored = explored;
}

Node::~Node() {
    delete this->pParent;
    delete this->pNext;
}

void Node::operator=(const Node &Node) {
    this->name = Node.getName();
    this->pParent = Node.getParent();
    this->pNext = Node.getNext();
    this->cost = Node.getCost();
    this->explored = Node.isExplored();
}

bool Node::isGoal(char goalCity) {
    return this->name == goalCity;
}

void Node::expand(vector<Link> &links, List *pFrontier, SEARCH_ALGORITHM searchAlgorithm)
{
    for (int i = 0; i < links.size(); i++) {
        Node *potentialNode = NULL;
        Link currentLink = links[i];
        if (currentLink.getCity1() == this->name || currentLink.getCity2() == this->name) {
            char name = (currentLink.getCity1() == this->name) ? currentLink.getCity2() : currentLink.getCity1();
            float cost = (searchAlgorithm == SEARCH_ALGORITHM::DEPTH_FIRST ||
                            searchAlgorithm == SEARCH_ALGORITHM::BREADTH_FIRST)
                            ? 0.0 // The cost term for both DEPTH_FIRST and BREADTH_FIRST algorithms is neglected.
                            : this->getCost() + currentLink.getLinkCost();

            potentialNode = new Node(name, this, NULL, cost);
            if (potentialNode->isQualified(pFrontier)) {
                potentialNode->pushNodeToList(pFrontier);
                /**
                 * If it is a depth first algorithm,
                 * then break the loop to pick only one child at a time.
                 */
                if (searchAlgorithm == SEARCH_ALGORITHM::DEPTH_FIRST) {
                    break;
                }
            }
        }
    }
}

bool Node::isQualified(List *pFrontier) {
    bool isQualified = true;
    Node *currentNode = pFrontier->getFirstNode();

    while (currentNode != NULL) {
        if ((currentNode->getName() == this->getName())) {
            if ((currentNode->getCost() <= this->getCost())) {
                isQualified = false;
            } else {
                currentNode->removeNodeFromList(pFrontier);
            }
            break;
        }
        currentNode = currentNode->getNext();
    }
    return isQualified;
}

Node* Node::findNextNodeToBeExplored(map<char, float> &heuristics, function<bool (const Node *nextNode, const Node *toBeExploredNode, map<char, float> &heuristics) > costComparator) {
    Node *toBeExploredNode = this->getNext();
    Node *nextNode = toBeExploredNode->getNext();

    while (nextNode != NULL) {
        if (costComparator(nextNode, toBeExploredNode, heuristics)) {
            toBeExploredNode = nextNode;
        }
        nextNode = nextNode->getNext();
    }
    return toBeExploredNode;
}


void Node::pushNodeToList(List *pFrontier) {
    Node *LastNode = pFrontier->getLastNode();

    if (pFrontier->getFirstNode() == NULL) {
        pFrontier->setFirstNode(this);
    }
    else {
        LastNode->setNext(this);
    }

    pFrontier->setLastNode(this);
}

void Node::removeNodeFromList(List *pFrontier) {
    Node *previousNode = pFrontier->getFirstNode();
    Node *currentNode = pFrontier->getFirstNode()->getNext();

    while ((currentNode != NULL) && (currentNode != this)) {
        previousNode = currentNode;
        currentNode = currentNode->getNext();
    }

    if (pFrontier->getFirstNode() == this) {
        pFrontier->setFirstNode(this->getNext());
    }
    else {
        previousNode->setNext(this->getNext());
    }

    if (pFrontier->getLastNode() == this) {
        pFrontier->setLastNode(previousNode);
    }
}

char Node::getName() const {
    return this->name;
}

Node* Node::getParent() const {
    return this->pParent;
}

Node* Node::getNext() const {
    return this->pNext;
}

float Node::getCost() const {
    return this->cost;
}

bool Node::isExplored() const {
    return this->explored;
}

void Node::setNext(Node *pNext) {
    this->pNext = pNext;
}

void Node::setExplored(bool value) {
    this->explored = value;
}