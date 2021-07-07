/*
 * File:   list.h
 * Author: Abdelrahman Abdelhamed
 *
 * Created on March 9, 2017
 */

#ifndef LIST_H
#define LIST_H

class Node;

class List {
private:
    Node *pFirstNode;
    Node *pLastNode;

public:
    /**
     * Default constructor
     */
    List();

    /**
     * A constructor that sets all private class members
     */
    List(Node *pFirstNode, Node *pLastNode);

    /**
     * A destructor
     */
    ~List();

    /**
     * Overloading an assignment operator
     * @param link
     */
    void operator=(const List &list);

    /**
     * Prints out on console the information of the nodes in the calling list.
     */
    void printList();

    /**
     * Print (to console) the solution path along with its cost.
     * It should also display number of nodes expanded (i.e. how many times the method node::expand(vector<link>, list*) was called
     */
    void printResult();

    /**
     * Accessors
     */
    Node* getFirstNode() const;
    Node* getLastNode() const;

    /**
     * Mutators
     */
    void setFirstNode(Node *pFirstNode);
    void setLastNode(Node *pLastNode);

};

#endif /* LIST_H */