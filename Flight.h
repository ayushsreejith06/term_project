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

    void addPassenger(string f_name, string l_name, string phone_num, int row_num, char seat_char);
    void remove_passenger(int row_num, char seat_char);
    vector<vector<Seat>> get_seats()const { return seats;}
    vector<Passenger> get_passengers()const { return passengers;}
    string get_route()const;
    



private:
    vector<vector<Seat>> seats;
    vector<Passenger> passengers;
    int number_of_rows;
    int number_of_seats_per_row;
    Route route;

};

#endif