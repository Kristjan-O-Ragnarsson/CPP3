#include <iostream>
#include <string>
#include <map>
#include "FlightBooking.h"
//#include "FlightPool.h"

using namespace std;


/*
FlightBooking::~FlightBooking(){
	cout << "Destructor";
}
*/
int main() {
    string input;
    int n, id;
    int counter = 0;
    std::map<int, int> flightPool;
    //FlightPool flightPool;
    FlightBooking fbooking[10];
    cout << "lol" << endl;
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
			if (!(flightPool.count(id))){
			    flightPool.insert(std::pair<int, int>(id,counter));
			    fbooking[counter] = FlightBooking(id, n, 0);
                fbooking[counter++].printStatus();
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
			if (fbooking[id].addPassengers(n)){
				cout << "reserved " << n << " seats" << endl;
			} else{
				cout << "Cannot perform this operation" << endl;
			}
		}else if (input == "cancel") {
			if (fbooking[id].removePassengers(n)){
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

