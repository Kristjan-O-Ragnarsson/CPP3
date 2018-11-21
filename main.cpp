#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
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
    //FlightBooking one(1,1,1);
    //FlightBooking two(2,2,2);
    //FlightBooking onne(1,1,1);

	//if(one < two) cout << "True";

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
		} else if (command == "showall") {
			fArr.printAll();
		} else if(command == "info") {
		    cout << "command is only for dynamic array";
            fArr.getInfo();
        } else if(command == "save") {
			fArr.saveAll();
		} else if(command == "load") {
		    fstream data("flights.bin", std::fstream::in | std::fstream::out | std::fstream::binary);
		    FlightBooking tmp;
            data.seekg(0);
            while (data.read((char*)&tmp, sizeof(FlightBooking))){
                fArr.createFlight(tmp.getId(), tmp.getRes(), tmp.getCap());
            }
		} else {
			cout << command << " is not a command" << endl;
		}
	}
    cout << "Exiting Press enter...";
    cin.ignore();
	return 0;
}

