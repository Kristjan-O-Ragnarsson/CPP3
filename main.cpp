#include <iostream>
#include <string>
#include <sstream>
#include "FlightBooking.h"
#include "FlightList.h"

using namespace std;


/*
FlightBooking::~FlightBooking(){
	cout << "Destructor";
}
*/
int main() {
    string command;
    string input;
    int n, id;
    FlightList fArr;
    //FlightPool flightPool;
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
	    getline(cin, input);
	    stringstream ss;
	    ss << input;
		ss >> command >> id >> n;
		if (command == "create"){
			if (!(fArr.checkIfFlightExist(id))){
			    if(!(fArr.createFlight(id, n))){
                    cout << "Cannot perform this operation" << endl;
			    }
			} else{
				cout << "Cannot perform this operation" << endl;
			}
		}else if (command == "delete") {
			if (fArr.deletFlight(id)){
				cout << "removed flight " << id << endl;
			} else{
				cout << "Cannot perform this operation" << endl;
			}
		}else if (command == "add") {
			if (fArr.addPassengers(id, n)){
				cout << "reserved " << n << " seats" << endl;
			} else{
				cout << "Cannot perform this operation" << endl;
			}
		}
		else if (command == "cancel") {
			if (fArr.removePassengers(id, n)){
				cout << "canceld " << n << " passengers" << endl;
			} else{
				cout << "Cannot perform this operation" << endl;
			}
		}else if (command == "quit") {
			break;
		} else if(command == "show") {
		    fArr.printStatus(id);
		} else if(command == "info") {
		    cout << "command is only for dynamic array";
            fArr.getInfo();
        } else {
			cout << command << " is not a command" << endl;
		}
	}

	return 0;
}

