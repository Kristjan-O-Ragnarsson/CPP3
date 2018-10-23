#include <iostream>
#include <string>
#include <map>
#include "FlightBooking.h"

using namespace std;


/*
FlightBooking::~FlightBooking(){
	cout << "Destructor";
}
*/
int main() {
    string input;
    int n, id;
    /*
	int reserved = 0,
		capacity = 0;
	cout << "Provide flight capacity: ";
	cin >> capacity;
	cout << "Provide number of reserved seats: ";
	cin >> reserved;
	FlightBooking booking(1, capacity, reserved);
	booking.printStatus();
     */
	while (true){
		cin >> input >> id >> n;
		if (input == "create"){
			if (flightPool.count(id)){
				cout << "added " << n << " passengers" << endl;
			} else{
				cout << "Cannot perform this operation" << endl;
			}
		}else if (input == "delete") {
			if (flightPool.count(id)){
				cout << "canceld " << n << " passengers" << endl;
			} else{
				cout << "Cannot perform this operation" << endl;
			}
		}else if (input == "add") {
			if (flightPool[id].removePassengers(n)){
				cout << "canceld " << n << " passengers" << endl;
			} else{
				cout << "Cannot perform this operation" << endl;
			}
		}else if (input == "cancel") {
			if (flightPool[id].removePassengers(n)){
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
	}

	return 0;
}

