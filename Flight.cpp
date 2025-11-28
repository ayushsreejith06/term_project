

#include "Flight.h"
#include "Seat.h"
#include "Route.h"
#include <vector>

Flight::Flight(int rows, int cols, string source, string dest): number_of_rows(rows), number_of_seats_per_row(cols), route(Route(source, dest)) {
    seats.resize(number_of_rows);
    for (int i = 0; i < number_of_rows; i++) {
        seats.at(i).resize(number_of_seats_per_row);
        for (int j = 0; j < number_of_seats_per_row; j++) {
            seats.at(i).at(j) = Seat(number_of_rows, number_of_seats_per_row + 'A');
        }
    }
}

void Flight::addPassenger(string f_name, string l_name, string phone_num, int row_num, char seat_char) {
    passengers.push_back(Passenger(f_name, l_name, phone_num, seats.at(row_num).at(seat_char - 'A')));

    seats.at(row_num).at(seat_char - 'A').set_passenger((passengers.at(passengers.size()-1)));
    seats.at(row_num).at(seat_char - 'A').set_status(true);
}

void Flight::remove_passenger(int row_num, char seat_char) {
    const Passenger* p = seats.at(row_num).at(seat_char - 'A').get_passenger();
    for (int i = 0; i < passengers.size(); i++) {
        if (&passengers.at(i) == p) {
            passengers.erase(passengers.begin() + i);
        }
    }
    seats.at(row_num).at(seat_char - 'A').set_status(false);
}