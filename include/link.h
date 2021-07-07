/* 
 * File:   link.h
 * Author: Abdelrahman Abdelhamed
 *
 * Created on March 5, 2017
 */

#ifndef LINK_H
#define LINK_H

class Link {
private:
    char city1;
    char city2;
    float linkCost;

public:
    /**
     * Default constructor
     */
    Link();

    /**
     * A constructor that sets all three private class members
     */
    Link(char city1, char city2, float linkCost);

    /**
     * A destructor
     */
    ~Link();

    /**
     * Overloading an assignment operator
     * @param link
     */
    void operator=(const Link &link);

    /**
     * Accessors
     */
    char getCity1() const;
    char getCity2() const;
    float getLinkCost() const;

};

#endif /* LINK_H */