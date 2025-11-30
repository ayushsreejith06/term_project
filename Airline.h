

#ifndef Airline_h
#define Airline_h
#include "Flight.h"
#include <string>


class Airline {
private:
    vector<Flight*> flights;
    string name;

public:
    Airline(string n): name(n) {}
    Flight* get_flight(int i)const { return flights.at(i);}
    void add_flight(Flight* flight) { flights.push_back(flight);}
    int get_num_flights()const { return flights.size();}
};

#endif