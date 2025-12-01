/*
 * File Name: Airline.cpp
 * Assignment: Term Project
 * Lab section: B01
 * Created by: Benjamin Anderson, Rolanted Ramos, Ayush Sreejith
 * Submission Date: Dec 1, 2025
 */

#include "airline.h"
#include "flight.h"
#include <string>


Airline::Airline(string n): name(n) {}
Flight* Airline::get_flight(int i)const { return flights.at(i);}
void Airline::add_flight(Flight* flight) { flights.push_back(flight);}
int Airline::get_num_flights()const { return flights.size();}