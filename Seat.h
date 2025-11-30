// Seat.h

#ifndef Seat_h
#define Seat_h
#include "Passenger.h"


class Passenger;

class Seat {
private:
	int row_number;
	char seat_character;
	Passenger* passenger;
	bool status;

public:
	Seat(int row = 0, char character = 0): row_number(row), seat_character(character), passenger(nullptr), status(false) {}
	int get_row_number()const { return row_number;}
	char get_seat_character()const { return seat_character;}
	const Passenger* get_passenger()const { return passenger;}
	bool get_status()const {return status;}
	void set_passenger(Passenger* pass) { passenger = pass;}
	void set_status(bool s) { status = s;}
	void set_seat_loc(int row, int character) {row_number = row; seat_character = character;}


};

#endif
