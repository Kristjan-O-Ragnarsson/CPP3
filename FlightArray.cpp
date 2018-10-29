//
// Created by Lenovo on 29.10.2018.
//

#include "FlightArray.h"
#include <iostream>

FlightArray::FlightArray() {
    size = 10;
    fArr = new FlightBooking[size];
    index = 0;

}

FlightArray::~FlightArray() {
    delete []fArr;
}

void FlightArray::insertFlight(FlightBooking flight) {
    if (index <= size -1){
        fArr[index++] = flight;
    } else {
        auto *tmp = new FlightBooking[size * 2];
        for (int i = 0; i < size; i ++){
            tmp[i] = fArr[i];
        }
        delete []fArr;
        fArr = tmp;
        size *= 2;
        fArr[index++] = flight;
    }
}

FlightBooking FlightArray::getFlight(int id) {
            return fArr[getIndex(id)];
}

void FlightArray::printStatus(int id) {
    if (checkIfFlightExist(id)){
        fArr[getIndex(id)].printStatus();
    } else {
        std::cout << "Flight Not Found"<<std::endl;
    }
}

int FlightArray::getIndex(int id) {
    for (int i = 0; i < size; i ++){
        if (fArr[i].getId() == id){
            return i;
        }
    }
}

bool FlightArray::removePassengers(int id, int n) {
    if (checkIfFlightExist(id)){
        return (fArr[getIndex(id)].removePassengers(n)) ? true : false;
    } else {
        return false;
    }

}

bool FlightArray::addPassengers(int id, int n) {
    if (checkIfFlightExist(id)){
        return (fArr[getIndex(id)].addPassengers(n)) ? true : false;
    } else {
        return false;
    }

}

bool FlightArray::deletFlight(int id) {
    if (checkIfFlightExist(id)){
        fArr[getIndex(id)] = FlightBooking();
        return true;
    } else {
        return false;
    }
}

bool FlightArray::checkIfFlightExist(int id) {
    for (int i = 0; i < size; i ++){
        if (fArr[i].getId() == id){
            return true;
        }
    }
    return false;
}

bool FlightArray::createFlight(int id, int cap) {
    if(!(checkIfFlightExist(id))){
        FlightBooking tmp = FlightBooking(id, cap, 0);
        insertFlight(tmp);
        tmp.printStatus();
        return true;
    } else {
        return false;
    }
}

void FlightArray::getInfo() {
    std::cout << "Size: "<< size << std::endl << "Index: " << index << std::endl;
}