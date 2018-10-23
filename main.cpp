#include <iostream>
#include <string>

using namespace std;

class FlightBooking {
public:
	FlightBooking(int id, int capacity, int reserved);
	//~FlightBooking();
	void printStatus();
private:
	int getFillLevel();
	int id;
	int capacity;
	int reserved;
};
void FlightBooking::printStatus()
{
	cout << "Flight " << id << " :" << reserved << "/" << capacity << "("<< getFillLevel() << "%)";
}

int FlightBooking::getFillLevel(){
	return 100 * reserved / capacity;

}

FlightBooking::FlightBooking(int id, int capacity, int reserved)
{
	this->id = id;
	this->capacity = capacity;
	this->reserved = reserved;
}

/*
FlightBooking::~FlightBooking(){
	cout << "Destructor";
}
*/
int main() {
	int reserved = 0,
		capacity = 0;
	cout << "Provide flight capacity: ";
	cin >> capacity;
	cout << "Provide number of reserved seats: ";
	cin >> reserved;
	FlightBooking booking(1, capacity, reserved);
	booking.printStatus();
	while (true)
	{
		//cin
		// some function for prasing
	}
	return 0;
}

