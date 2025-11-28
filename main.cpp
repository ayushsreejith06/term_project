
#include <stdlib.h>
#include <iostream>
#include "Flight.h"
using namespace std;

void cleanStandardInputStreamm(void);
void pressEnter(void);
int menu(void);
void clearScreen(void);
void displayHeader();
void displayPassengers(Flight& f);

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
    cout << "\n<<<Press Return to continue";
    cin.get();
}

void clearScreen() {
#ifdef UNIX
    system("clear");
#else
    system("clr");
#endif
}

int menu() {
    int choice = -1;
    clearScreen();

    cout << "Please select one of the following options:\n\n";
    cout << "1. Select Flight\n";
    cout << "2. Display Flight Seat Map.\n";
    cout << "3. Display Passenger Information.\n";
    cout << "4. Add a New Passenger\n";
    cout << "5. Remove an Existing Passenger\n";
    cout << "6. Save Data\n";
    cout << "7. Quit.\n";
    cout << "\nEnter your choice: (1, 2, 3, 4, 5, 6 or 7)";
    cin >> choice;

    cleanStandardInputStream();
    return choice;
}

void displayHeader() {
    clearScreen();
    cout << "\nFlight Management Application - Spring 2020\n";
    cout << "\nVirsion: 1.0";
    cout << "\nTerm Project";
    cout << "\nProduced by: Benjamin Anderson, Rolanted Ramos, Ayush Sreejith\n\n";
    pressEnter();
}




int main(void) {
    int choice;
    while (choice = menu()) {
        switch (choice) {
            case 1:
                f.show_seat_map();
                pressEnter();
                break;
            case 2:
                displayPassengers(f);
                pressEnter();
                break;
            case 3:
                add_passenger(f);
                break;
            case 4:
                remove_passenger(f);
                break;
            case 5:
                save_data(f);
                break;
            case 6:
                break;
        }
    }
}