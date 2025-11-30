
#include <cstdlib>
#include <iostream>
#include <fstream>
#include "Flight.h"
#include "Airline.h"
#include "Seat.h"
#include "Passenger.h"
#include "Route.h"
using namespace std;

void cleanStandardInputStream(void);
void pressEnter(void);
int menu(void);
void displayHeader();
void add_passenger(Flight* f);
void remove_passenger(Flight* f);
void save_data(Airline& a);
void read_files(Airline& airline);
Flight * select_flight(Airline& a);


void cleanStandardInputStream(void) 
{
    int leftover;
    do 
    {
        leftover = cin.get();
    } while (leftover != '\n' && leftover != EOF);
}


void pressEnter()
{
    cout << "\n<<<Press Return to continue>>>";
    cin.get();
}

int menu() {

    int choice = -1;

    cout << "\nPlease select one of the following options:\n\n";
    cout << "1. Select Flight\n";
    cout << "2. Display Flight Seat Map.\n";
    cout << "3. Display Passenger Information.\n";
    cout << "4. Add a New Passenger\n";
    cout << "5. Remove an Existing Passenger\n";
    cout << "6. Save Data\n";
    cout << "7. Quit.\n";
    cout << "\nEnter your choice: (1, 2, 3, 4, 5, 6 or 7) ";
    cin >> choice;

    cleanStandardInputStream();
    return choice;
}

void displayHeader() {
    cout << endl <<"Version: 1.0" << endl;
    cout << "Term Project - Flight Management Application System" << endl;
    cout << "Produced by group#: 13" << endl;
    cout << "Names: Benjamin Anderson, Rolanted Ramos, Ayush Sreejith" << endl << endl;
    pressEnter();
}

void read_files(Airline& airline) {
    ifstream in_flights("flights.txt");
    if (in_flights.fail()) {
        cout << "ERROR opening flights file... quitting\n";
        exit(1);
    }

    ifstream in_passengers("passengers.txt");
    if (in_passengers.fail()) {
        cout << "ERROR opening passengers file... quitting\n";
        exit(1);
    }

    while (!in_flights.eof()) {
        string id;
        string departure;
        string destination;
        int rows;
        int cols;

        in_flights >> id >> departure >> destination >> rows >> cols;
        airline.add_flight(new Flight(id, rows, cols, destination, departure));
    }
    
    in_flights.close();

    while (!in_passengers.eof()) {
        string flight_id;
        string fname;
        string lname;
        string phone;
        string seat;
        string passenger_id;

        in_passengers >> flight_id >> fname >> lname >> phone >> seat >> passenger_id;
        if (in_passengers.eof())
            break;

        Flight* flight;

        for (int i = 0; i < airline.get_num_flights(); i++) {
            if (airline.get_flight(i)->get_id() == flight_id) {
                flight = airline.get_flight(i);
            }
        }
        int seat_row = stoi(seat.substr(0, seat.size()-1));

        char seat_char = seat.at(seat.size()-1);

        flight->addPassenger(new Passenger(passenger_id, fname, lname, phone, flight->get_seat(seat_row, seat_char)), seat_row, seat_char);
    }

    in_passengers.close();
}

void add_passenger(Flight* f) {
    string id;
    cout << endl << "Please enter the passenger id: ";
    cin >> id;
    cleanStandardInputStream();
    string fname;
    cout << "Please enter the passenger first name: ";
    cin >> fname;
    cleanStandardInputStream();
    string lname;
    cout << "Please enter the passenger last name: ";
    cin >> lname;
    cleanStandardInputStream();
    string phone;
    cout << "Please enter a phone number: ";
    cin >> phone;
    cleanStandardInputStream();
    int seat_row;
    cout << "Enter the passenger's desired row: ";
    cin >> seat_row;
    cleanStandardInputStream();
    char seat_char;
    cout << "Enter the passenger's desired seat: ";
    cin >> seat_char;
    cleanStandardInputStream();

    f->addPassenger(new Passenger(id, fname, lname, phone, f->get_seat(seat_row, seat_char)), seat_row, seat_char);
}

void remove_passenger(Flight* f) {
    string id;
    cout << "Enter the id of the passenger that needs to be removed: ";
    cin >> id;
    
    cleanStandardInputStream();
    for (int i = 0; i < f->get_number_of_passengers(); i++) {
        if (f->get_passenger(i)->get_id() == id) {
            f->remove_passenger(f->get_passenger(i)->get_seat()->get_row_number(), f->get_passenger(i)->get_seat()->get_seat_character());
            break;
        }
    }
}


Flight * select_flight(Airline& a) {
    cout << endl << "Here is the list of available flights. Please select one:" << endl;
    for (int i = 0; i < a.get_num_flights(); i++) {
        cout << "    " << i+1 << ".\t" << a.get_flight(i)->get_id() << '\t' << a.get_flight(i)->get_route().get_source() << '\t' << a.get_flight(i)->get_route().get_destination() << '\t' << a.get_flight(i)->get_number_of_rows() << '\t' << a.get_flight(i)->get_number_of_seats_per_row() << endl;
    }
    cout << "\nEnter your choice: ";
    int i;
    cin >> i;
    cleanStandardInputStream();
    i--;
    
    cout << "You have selected " << a.get_flight(i)->get_id() << " from " << a.get_flight(i)->get_route().get_source() << " to " << a.get_flight(i)->get_route().get_destination() << endl;

    pressEnter();
    return a.get_flight(i);
}

void save_data(Airline& a) {
    char in;
    cout << "Do you want to save the data in the \"passengers.txt\"? Please answer <Y or N> ";
    cin >> in;

    if (in == 'N')
        return;

    ofstream out_pass("passengers.txt");
    if (out_pass.fail()) {
        cout << "ERROR opening passengers file... quitting\n";
        exit(1);
    }

    for (int i = 0; i < a.get_num_flights(); i++) {
        for (int j = 0; j < a.get_flight(i)->get_number_of_passengers(); j++) {
            const Passenger* p = a.get_flight(i)->get_passenger(j);
            out_pass << a.get_flight(i)->get_id() << '\t' << p->get_first_name() << '\t' << p->get_last_name() << '\t' << p->get_phone_number() << '\t' << to_string(p->get_seat()->get_row_number()) << (char)p->get_seat()->get_seat_character() << '\t' << p->get_id() << endl;
        }
    }

    out_pass.close();

    cout << endl << "All the data in passenger list were saved." << endl;

}


int main(void) {
    displayHeader();
    Airline airline = Airline("hello");
    read_files(airline);
    Flight* f = airline.get_flight(0);
    int choice = menu();
    while (choice != 7) {
        switch (choice) {
            case 1:
                f = select_flight(airline);
                break;
            case 2:
                f->show_seat_map();
                pressEnter();
                break;
            case 3:
                f->print_passenger_info();
                pressEnter();
                break;
            case 4:
                add_passenger(f);
                break;
            case 5:
                remove_passenger(f);
                break;
            case 6:
                save_data(airline);
                break;
        }
        choice = menu();
    }
    cout << "\nProgram terminated\n";
}