//
// Created by Lenovo on 29.10.2018.
//

#include "FlightArray.h"

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
        FlightBooking *tmp = new FlightBooking[size * 2];
        for (int i = 0; i < size; i ++){
            tmp[i] = fArr[i];
        }
        delete []fArr;
        fArr = tmp;
        size *= 2;
        fArr[index++] = flight;
    }
}