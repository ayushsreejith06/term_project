

#include "Flight.h"
#include "Seat.h"
#include "Route.h"
#include <vector>
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


Flight::Flight(string id, int rows, int cols, string source, string dest): number_of_rows(rows), number_of_seats_per_row(cols), route(Route(source, dest)) {
    this->id = id;
    seats.resize(number_of_rows);
    for (int i = 0; i < number_of_rows; i++) {
        seats.at(i).resize(number_of_seats_per_row);
        for (int j = 0; j < number_of_seats_per_row; j++) {
            seats.at(i).at(j).set_seat_loc(i, j + 'A');
        }
    }
}

void Flight::addPassenger(Passenger* passenger, int row_num, char seat_char) {
    passengers.push_back(passenger);

    seats.at(row_num).at(seat_char - 'A').set_passenger((passengers.at(passengers.size()-1)));
    seats.at(row_num).at(seat_char - 'A').set_status(true);
}

void Flight::remove_passenger(int row_num, char seat_char) {
    const Passenger* p = seats.at(row_num).at(seat_char - 'A').get_passenger();
    for (int i = 0; i < (int) passengers.size(); i++) {
        if (passengers.at(i) == p) {
            passengers.erase(passengers.begin() + i);
            break;
        }
    }
    cout << endl << "Passenger " << p->get_first_name() << ' ' << p->get_last_name() << " was successfully removed from flight " << id << endl;
    delete p;
    seats.at(row_num).at(seat_char - 'A').set_status(false);
}

void Flight::show_seat_map()const {
    cout << endl << "Aircraft Seat Map for flight " << id << endl << "  ";
    string line = "   ";
    for (int j = 0; j < number_of_seats_per_row; j++) {
        line += "+---";
        cout << "   " << (char)j + 'A';
    }
    cout << endl;
    line += '+';
    for (int i = 0; i < number_of_rows; i++) {
        cout << line << endl;
        cout << i << (i < 10 ?"  ":" ");
        for (int j = 0; j < number_of_seats_per_row; j++) {
            cout << "| " << (seats.at(i).at(j).get_status()?'x':' ') << ' ';
        }
        cout << '|' << endl;
    }
    cout << line << endl;
}

void Flight::print_passenger_info()const {
    cout << left;
    cout << endl << "Passenger List (Flight:" << id << " from " << route.get_source() << " to " <<route.get_destination() << ')' << endl;
    cout << endl << setw(20) <<"First Name" << setw(20) << "Last Name" << setw(20) << "Phone" << setw(5) << "Row" << setw(5) << "Seat" << "ID" << endl;
    for (int i = 0; i < (int) passengers.size(); i++) {
        const Passenger* p = passengers.at(i);
        const Seat* s = p->get_seat();
        cout << string(75, '-') << endl;
        cout << setw(20) << p->get_first_name() << setw(20) << p->get_last_name() << setw(20) << p->get_phone_number() << setw(5) << s->get_row_number() << setw(5) << s->get_seat_character() << p->get_id() << endl;
    }
    cout << string(75, '-') << endl;
}