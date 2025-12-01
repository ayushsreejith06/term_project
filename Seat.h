/*
 * File Name: seat.h
 * Assignment: Term Project
 * Lab section: B01
 * Created by: Benjamin Anderson, Rolanted Ramos, Ayush Sreejith
 * Submission Date: Dec 1, 2025
 */

#ifndef Seat_h
#define Seat_h
#include "passenger.h"


class Passenger;

class Seat {
private:
	int row_number;
	char seat_character;
	Passenger* passenger;
	bool status;

public:
	Seat(int row = 0, char character = 0);
	int get_row_number()const;
	char get_seat_character()const;
	const Passenger* get_passenger()const;
	bool get_status()const;
	void set_passenger(Passenger* pass);
	void set_status(bool s);
	void set_seat_loc(int row, int character);


};

#endif
