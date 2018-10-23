#include <iostream>
#include <string>

using namespace std;

class FlightBooking {
public:
	FlightBooking(int id, int capacity, int reserved);
	//~FlightBooking();
	void printStatus();
	bool addPassengers(int n);
	bool removePassengers(int n);
private:
	int getFillLevel();
	int id_m;
	int capacity_m;
	int reserved_m;
};
void FlightBooking::printStatus()
{
	cout << "Flight " << id_m << " :" << reserved_m << "/" << capacity_m << "("<< getFillLevel() << "%)";
}

int FlightBooking::getFillLevel(){
	return 100 * reserved_m / capacity_m;

}

FlightBooking::FlightBooking(int id, int capacity, int reserved)
{
    if(reserved < abs(reserved)){
        reserved = 0;
    }
	id_m = id;
	capacity_m = capacity;
	reserved_m = reserved;
}

bool FlightBooking::addPassengers(int n) {
    if ( (reserved_m + n) < (reserved_m * 1.05)){
        reserved_m += n;
        return true;
    } else {
        return false;
    }

}

bool FlightBooking::removePassengers(int n) {
    if (reserved_m - n >= 0){
        reserved_m -= n;
        return true;
    } else {
        return false;
    }

}

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
	while (true)
	{
		cin >> input;
		if (1){
            break;
		}
	}
	return 0;
}

