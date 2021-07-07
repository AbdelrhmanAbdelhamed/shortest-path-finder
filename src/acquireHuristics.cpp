/* 
 * File:   acquireHuristics.cpp
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

void acquireHuristics(map<char, float> &heuristics) {
    ifstream readFromHuristicsFile("huristics.txt"); // trying to open the huristics file. (dist folder).
    char city = ' ';
    float heuristic = 0.0;

    if (readFromHuristicsFile.is_open()) {
        while (!readFromHuristicsFile.eof()) {

            readFromHuristicsFile >> city;
            city = toupper(city);
            readFromHuristicsFile >> heuristic;
            if (heuristics.count(city))
                heuristics[city] = heuristic;
            else
                cout << "Wrong city(" << city << "). (No such city provided during links acquisition process).";
        }
        readFromHuristicsFile.close();
    } else {
        cout << "Error during open the file (maybe a wrong path or it does not exist)." << endl;
    }
}