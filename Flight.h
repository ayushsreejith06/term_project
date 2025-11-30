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
    Flight(string id, int rows, int cols, string source, string dest);
    int get_number_of_rows()const { return number_of_rows;}
    int get_number_of_seats_per_row()const { return number_of_seats_per_row;}

    void addPassenger(Passenger* passenger, int row_num, char seat_char);
    void remove_passenger(int row_num, char seat_char);
    const Seat* get_seat(int row_num, char seat_char)const { return &seats.at(row_num).at(seat_char - 'A');}
    const Passenger* get_passenger(int i)const { return passengers.at(i);}
    const Route& get_route()const { return route;}
    string get_id()const { return id;}
    void show_seat_map()const;
    void print_passenger_info()const;
    int get_number_of_passengers()const { return passengers.size();}
    



private:
    vector<vector<Seat>> seats;
    vector<Passenger*> passengers;
    int number_of_rows;
    int number_of_seats_per_row;
    Route route;
    string id;

};

#endif