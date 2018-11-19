//
// Created by new pc on 23/10/2018.
//
#include "FlightPool.h"
#include "FlightBooking.h"

FlightPool::FlightPool() {
}


bool FlightPool::createFlight(int id, int cap){
    tmp = FlightBooking(id, cap, 0);
    fArr.insertFlight(tmp);

}

bool FlightPool::deletFlight(int id){
    arrId = flightPool[id];
    arr[arrId] = FlightBooking();
    flightPool.erase(id);
    inUse--;
    empty[arrId] = true;

}

bool FlightPool::removePassengers(int id, int n) {
    if (arr[flightPool[id]].removePassengers(n)){
        return true;
    } else {
        return false;
    }
}

bool FlightPool::checkIfFlightExist(int id) {
    if (flightPool.count(id) > 0){
        return true;
    } else {
        return false;
    }
}

bool FlightPool::addPassengers(int id, int n) {
    if (arr[flightPool[id]].addPassengers(n)){
        return true;
    } else {
        return false;
    }
}

void FlightPool::printStatus(int id) {
    arr[flightPool[id]].printStatus();

}