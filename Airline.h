/*
 * File Name: Airline.h
 * Assignment: Term Project
 * Lab section: B01
 * Created by: Benjamin Anderson, Rolanted Ramos, Ayush Sreejith
 * Submission Date: Dec 1, 2025
 */

#ifndef Airline_h
#define Airline_h
#include "Flight.h"
#include <string>


class Airline {
private:
    vector<Flight*> flights;
    string name;

public:
    Airline(string n);
    Flight* get_flight(int i)const;
    void add_flight(Flight* flight);
    int get_num_flights()const;
};

#endif