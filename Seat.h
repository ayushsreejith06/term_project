// Seat.h

#ifndef Seat_h
#define Seat_h
#include "Passenger.h"


class Seat {
public:
	Seat(int row, char character): row_number(row), seat_character(character), passenger(nullptr), status(0) {}
	int get_row_number()const { return row_number;}
	char get_seat_character()const { return seat_character;}
	const Passenger* get_passenger()const { return passenger;}
	bool get_status()const ( return status;)
	void set_passenger(Passenger& pass) { passenger = &pass;}
	void set_status(bool s) { status = s;}

private:
	int row_number;
	char seat_character;
	Passenger* passenger;
	bool status;
};

#endif
