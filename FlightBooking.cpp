//
// Created by Lenovo on 23.10.2018.
//
#include <iostream>
#include <sstream>
#include "FlightBooking.h"

using namespace std;

FlightBooking::FlightBooking(int id, int capacity, int reserved)
{
    id_m = id;
    capacity_m = capacity;
    reserved_m = reserved;
}

string FlightBooking::printStatus()
{
    ostringstream os;
    if(id_m > 0){
        os << "Flight " << id_m << " :" << reserved_m << "/" << capacity_m << "("<< getFillLevel() << "%)"<< endl;
    } else {
        os << "Flight not found" << endl;
    }
    return os.str();

}

int FlightBooking::getFillLevel(){
    if (capacity_m == 0){
        return 0;
    } else{
        return 100 * reserved_m / capacity_m;
    }
}

bool FlightBooking::addPassengers(int n) {
    if (n < abs(n)) return false;
    if ( (reserved_m + n) < (capacity_m * 1.05)){
        reserved_m += n;
        return true;
    } else {
        return false;
    }

}

bool FlightBooking::removePassengers(int n) {
    if (n < abs(n)) return false;
    if (reserved_m - n >= 0){
        reserved_m -= n;
        return true;
    } else {
        return false;
    }

}

int FlightBooking::getId() {
    return id_m;
}

int FlightBooking::getCap() {
    return capacity_m;
}

int FlightBooking::getRes() {
    return  reserved_m;
}

bool operator>(const FlightBooking& fFlight, const FlightBooking& sFlight) {
    return fFlight.reserved_m > sFlight.reserved_m;
}


bool operator==(const FlightBooking& fFlight, const FlightBooking& sFlight){
    return fFlight.reserved_m == sFlight.reserved_m;
}

ostream& operator<<(ostream &ostr, FlightBooking fligh){
    return ostr << fligh.printStatus();
}