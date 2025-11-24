// Passenger.h

class Passenger {
public:
	Passenger();
	string get_first_name()const{ return first_name}
	string get_last_name()const{ return last_name}
	string get_phone_number()const{ return phone_number}
	
private:
	string first_name;
	string last_name;
	string phone_number;
}