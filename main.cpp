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
    int n;
	int reserved = 0,
		capacity = 0;
	cout << "Provide flight capacity: ";
	cin >> capacity;
	cout << "Provide number of reserved seats: ";
	cin >> reserved;
	FlightBooking booking(1, capacity, reserved);
	booking.printStatus();
	while (true){
		cin >> input >> n;
		if (input == "add"){
			if (booking.addPassengers(n)){
				cout << "added " << n << " passengers" << endl;
			} else{
				cout << "Cannot perform this operation" << endl;
			}
		}else if (input == "cancel") {
			if (booking.removePassengers(n)){
				cout << "canceld " << n << " passengers" << endl;
			} else{
				cout << "Cannot perform this operation" << endl;
			}
		}else if (input == "quit") {
			break;
		} else {
			cout << input << " is not a command" << endl;
		}
		input = "";
		n = 0;
		booking.printStatus();
	}

	return 0;
}

