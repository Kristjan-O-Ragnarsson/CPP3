//
// Created by Lenovo on 23.10.2018.
//
#include <iostream>
#include "FlightBooking.h"

using namespace std;

FlightBooking::FlightBooking(int id, int capacity, int reserved)
{
    id_m = id;
    capacity_m = capacity;
    reserved_m = reserved;
}

void FlightBooking::printStatus()
{
    if(id_m > 0){
        cout << "Flight " << id_m << " :" << reserved_m << "/" << capacity_m << "("<< getFillLevel() << "%)"<< endl;
    } else {
        cout << "Flight not found" << endl;
    }

}

int FlightBooking::getFillLevel(){
    return 100 * reserved_m / capacity_m;

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


