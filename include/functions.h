/* 
 * File:   functions.h
 * Author: Abdelrahman Abdelhamed
 *
 * Created on March 5, 2017
 */

#include <map>
#include <vector>

using namespace std;

#include "link.h"

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

/**
 * 
 *  Takes from the user, by reference, constructed values of links which will be
 *  pushed_back into the vector structure as a triplet of the private class link members. This
 *  triplet is entered by the user (e.g. a b 3). A terminating character should be included to stop
 *  the acquisition process.
 * 
 * @param links - A reference to the vector links
 * 
 */
void acquireLinks(vector<Link> &links, map<char, float> &heuristics);


/**
 * 
 * Takes from the user a map by reference,
 * And assign Heuristics for each requested node.
 * 
 * @param heuristics - A reference to the map heuristics
 * 
 */
void acquireHuristics(map<char, float> &heuristics);

#endif /* FUNCTIONS_H */