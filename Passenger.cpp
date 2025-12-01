/*
 * File Name: Passenger.cpp
 * Assignment: Term Project
 * Lab section: B01
 * Created by: Benjamin Anderson, Rolanted Ramos, Ayush Sreejith
 * Submission Date: Dec 1, 2025
 */



#include <string>
#include "seat.h"
#include "passenger.h"
using namespace std;


Passenger::Passenger(string pass_id, string f_name, string l_name, string phone_num, const Seat* s): id(pass_id), first_name(f_name), last_name(l_name), phone_number(phone_num), seat(s) {}

string Passenger::get_first_name()const{ return first_name;}
string Passenger::get_last_name()const{ return last_name;}
string Passenger::get_phone_number()const{ return phone_number;}
const Seat* Passenger::get_seat()const {return seat;}
string Passenger::get_id()const { return id;}