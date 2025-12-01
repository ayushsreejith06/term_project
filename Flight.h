/*
 * File Name: flight.h
 * Assignment: Term Project
 * Lab section: B01
 * Created by: Benjamin Anderson, Rolanted Ramos, Ayush Sreejith
 * Submission Date: Dec 1, 2025
 */


#ifndef Flight_h
#define Flight_h

#include <vector>
#include "seat.h"
#include "passenger.h"
#include "route.h"
using namespace std;



class Flight {
public:
    Flight(string id, int rows, int cols, string source, string dest);
    int get_number_of_rows()const;
    int get_number_of_seats_per_row()const;

    void addPassenger(Passenger* passenger, int row_num, char seat_char);
    void remove_passenger(int row_num, char seat_char);
    const Seat* get_seat(int row_num, char seat_char)const;
    const Passenger* get_passenger(int i)const;
    const Route& get_route()const;
    string get_id()const;
    void show_seat_map()const;
    void print_passenger_info()const;
    int get_number_of_passengers()const;
    



private:
    vector<vector<Seat>> seats;
    vector<Passenger*> passengers;
    int number_of_rows;
    int number_of_seats_per_row;
    Route route;
    string id;

};

#endif