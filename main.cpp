#include <iostream>
#include <string>
#include "FlightBooking.h"

using namespace std;



/*
FlightBooking::~FlightBooking(){
	cout << "Destructor";
}
*/
int main() {
    string input;
	int reserved = 0,
		capacity = 0;
	cout << "Provide flight capacity: ";
	cin >> capacity;
	cout << "Provide number of reserved seats: ";
	cin >> reserved;
	FlightBooking booking(1, capacity, reserved);
	booking.printStatus();
	/*while (true)
	{
		cin >> input;
        if (1){
            break;
        }
		// some function for prasing
	}*/
	return 0;
}

