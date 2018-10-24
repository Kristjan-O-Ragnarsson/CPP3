//
// Created by new pc on 23/10/2018.
//
#include "FlightPool.h"
#include "FlightBooking.h"

FlightPool::FlightPool() {
}

FlightPool::~FlightPool(){
    //del arr_m;
}

int FlightPool::getId() {
    for (int i = 0; i < 10; i++){
        if (i != 0){
            return i;
        }
    }
}

bool FlightPool::createFlight(int id, int cap){
    if (inUse < 10){
        arrId = getId();
        flightPool.insert(std::pair<int, int>(id, arrId));
        arr[arrId] = FlightBooking(id, cap, 0);
        empty[arrId] = false;
        arr[arrId].printStatus();
        inUse++;
        return true;

    } else {
        return false;
    }

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