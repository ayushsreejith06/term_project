/*
 * File Name: route.h
 * Assignment: Term Project
 * Lab section: B01
 * Created by: Benjamin Anderson, Rolanted Ramos, Ayush Sreejith
 * Submission Date: Dec 1, 2025
 */

#ifndef Route_h
#define Route_h

#include <string>
using namespace std;

class Route {
public:
    Route(string s, string d);
    string get_source()const;
    string get_destination()const;

private:
    string source;
    string destination;
};

#endif