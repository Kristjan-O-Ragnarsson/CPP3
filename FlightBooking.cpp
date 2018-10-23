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
    cout << "Flight " << id_m << " :" << reserved_m << "/" << capacity_m << "("<< getFillLevel() << "%)";
}

int FlightBooking::getFillLevel(){
    return 100 * reserved_m / capacity_m;

}


