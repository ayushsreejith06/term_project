// Flight.h


#ifndef Flight_h
#define Flight_h

#include <vector>
#include "Seat.h"
#include "Passenger.h"
#include "Route.h"
using namespace std;



class Flight {
public:
    Flight(int rows, int cols, string source, string dest);
    int get_number_of_rows()const { return number_of_rows;}
    int get_number_of_seats_per_row()const { return number_of_seats_per_row;}
    



private:
    vector<vector<Seat>> seats;
    vector<Passenger> passengers;
    int number_of_rows;
    int number_of_seats_per_row;
    Route route;

};

#endif