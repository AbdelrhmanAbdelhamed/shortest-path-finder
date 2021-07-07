/* 
 * File:   acquireLinks.cpp
 * Author: Abdelrahman Abdelhamed
 * 
 * Created on March 5, 2017
 */

#include <vector>
#include <iostream>
#include <fstream>
#include <map>

#include "../include/functions.h"
#include "../include/link.h"

using namespace std;

void acquireLinks(vector<Link> &links, map<char, float> &heuristics) {
    char city1 = ' ';
    char city2 = ' ';
    float linkCost = 0.0;

    ifstream readFromlinksFile("links.txt"); // trying to open the links file. (dist folder).

    if (readFromlinksFile.is_open()) {
        while (!readFromlinksFile.eof()) {

            readFromlinksFile >> city1;
            city1 = toupper(city1);

            readFromlinksFile >> city2;
            city2 = toupper(city2);

            readFromlinksFile >> linkCost;

            heuristics[city1] = 0.0;
            heuristics[city2] = 0.0;

            Link link = Link(city1, city2, linkCost); // Wrapping the input into a link object.
            links.push_back(link); // Filling the vector (Adding new Link).
        }
        readFromlinksFile.close();
    } else {
        cout << "Error during open the file (maybe a wrong path or it does not exist)." << endl;
    }
}
