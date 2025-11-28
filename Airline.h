

#ifndef Airline_h
#define Airline_h
#include "Flight.h"
#include <string>


class Airline {
private:
    vector<Flight> flights;
    string name;

public:
    Airline(string n): name(n) {}
    const Flight& get_flight(int i)const { return flights.at(i);}
    void add_flight(int rows, int cols, string source, string dest) { flights.push_back(Flight(rows, cols, source, dest));}
};

#endif