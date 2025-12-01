/*
 * File Name: seat.cpp
 * Assignment: Term Project
 * Lab section: B01
 * Created by: Benjamin Anderson, Rolanted Ramos, Ayush Sreejith
 * Submission Date: Dec 1, 2025
 */


#include "seat.h"
#include "passenger.h"



Seat::Seat(int row, char character): row_number(row), seat_character(character), passenger(nullptr), status(false) {}
int Seat::get_row_number()const { return row_number;}
char Seat::get_seat_character()const { return seat_character;}
const Passenger* Seat::get_passenger()const { return passenger;}
bool Seat::get_status()const {return status;}
void Seat::set_passenger(Passenger* pass) { passenger = pass;}
void Seat::set_status(bool s) { status = s;}
void Seat::set_seat_loc(int row, int character) {row_number = row; seat_character = character;}