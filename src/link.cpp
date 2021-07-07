/* 
 * File:   link.cpp
 * Author: Abdelrahman Abdelhamed
 * 
 * Created on March 5, 2017
 */

#include "../include/link.h"

Link::Link() {
    this->city1 = ' ';
    this->city2 = ' ';
    this->linkCost = 0.0;
}

Link::Link(char city1, char city2, float linkCost) {
    this->city1 = city1;
    this->city2 = city2;
    this->linkCost = linkCost;
}

Link::~Link() {
}

void Link::operator=(const Link &link) {
    this->city1 = link.getCity1();
    this->city2 = link.getCity2();
    this->linkCost = link.getLinkCost();
}

char Link::getCity1() const {
    return this->city1;
}

char Link::getCity2() const {
    return this->city2;
}

float Link::getLinkCost() const {
    return this->linkCost;
}