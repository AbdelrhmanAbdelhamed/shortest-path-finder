/* 
 * File:   node.h
 * Author: Abdelrahman Abdelhamed
 *
 * Created on March 5, 2017
 */

#ifndef NODE_H
#define NODE_H

#include <vector>
#include <map>
#include <functional>

#include "searchAlgorithm.h"
#include "link.h"
#include "list.h"

class List;

class Node {
private:
    char name;
    Node *pParent;
    Node *pNext;
    float cost;
    bool explored;

public:
    /**
     * Default constructor
     */
    Node();

    /**
     * A constructor that sets all 5 private class members
     */
    Node(char name, Node *pParent, Node *pNext, float cost, bool explored = false);

    /**
     * A destructor
     */
    ~Node();

    /**
     * Overloading an assignment operator
     * @param link
     */
    void operator=(const Node &node);

    /**
     * returns true if the calling node name is the same as the goalCity, and returns false otherwise.
     * @param goalCity
     */
    bool isGoal(char goalCity);

    /**
     * Finds potential sibling nodes of the calling node
     */
    void expand(vector<Link> &links, List *pFrontier, SEARCH_ALGORITHM searchAlgorithm);

    /**
     * Determines if the calling node (which is a potential node) is qualified to be added to the input argument list.
     * Also discard from the list any node once a cheaper replacement for it is found.
     * @param pFrontier
     */
    bool isQualified(List *pFrontier);

    /**
     *  Determines if the next node to be expanded based on the costComparator callback function.  
     */
    Node* findNextNodeToBeExplored(map<char, float> &heuristics, function<bool (const Node *nextNode, const Node *toBeExploredNode, map<char, float> &heuristics) > costComparator);

    /**
     * Pushes potential nodes to list pFrontier
     */
    void pushNodeToList(List *pFrontier);

    /**
     * Removes unwanted nodes from list pFrontier
     */
    void removeNodeFromList(List *pFrontier);

    /**
     * Accessors
     */
    char getName() const;
    Node* getParent() const;
    Node* getNext() const;
    float getCost() const;
    bool isExplored() const;

    /**
     * Mutators
     */
    void setNext(Node *pNext);
    void setExplored(bool value);

};

#endif /* NODE_H */