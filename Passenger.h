// Passenger.h


#ifndef Passenger_h
#define Passenger_h
#include <string>
#include "seat.h"
using namespace std;

class Seat;

class Passenger {
public:
	Passenger(string pass_id, string f_name, string l_name, string phone_num, const Seat* s): id(pass_id), first_name(f_name), last_name(l_name), phone_number(phone_num), seat(s) {}
	string get_first_name()const{ return first_name;}
	string get_last_name()const{ return last_name;}
	string get_phone_number()const{ return phone_number;}
	const Seat* get_seat()const {return seat;}
	string get_id()const { return id;}
	
	
private:
	string id;
	string first_name;
	string last_name;
	string phone_number;
	const Seat* seat;
};

#endif