// Seat.h

class Seat {
	public:
		int get_row_number()const { return row_number};
		char get_seat_character()const { return seat_character;}
	private:
		int row_number;
		int seat_character;
}
