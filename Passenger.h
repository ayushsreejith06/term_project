/*
 * File Name: passenger.h
 * Assignment: Term Project
 * Lab section: B01
 * Created by: Benjamin Anderson, Rolanted Ramos, Ayush Sreejith
 * Submission Date: Dec 1, 2025
 */


#ifndef Passenger_h
#define Passenger_h
#include <string>
#include "seat.h"
using namespace std;

class Seat;

class Passenger {
public:
	Passenger(string pass_id, string f_name, string l_name, string phone_num, const Seat* s);
	string get_first_name()const;
	string get_last_name()const;
	string get_phone_number()const;
	const Seat* get_seat()const;
	string get_id()const;
	
	
private:
	string id;
	string first_name;
	string last_name;
	string phone_number;
	const Seat* seat;
};

#endif