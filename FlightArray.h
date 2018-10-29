//
// Created by Lenovo on 29.10.2018.
//

#ifndef CPP3_FLIGHTARRAY_H
#define CPP3_FLIGHTARRAY_H

#include "FlightBooking.h"

class FlightArray {
private:
    FlightBooking *fArr;
    int getIndex(int id);
    int size;
    int index;
public:
    FlightArray();
    ~FlightArray();
    void insertFlight(FlightBooking flight);
    FlightBooking getFlight(int ind);
    bool removePassengers(int id, int n);
    bool deletFlight(int id);
    bool addPassengers(int id, int n);
    void printStatus(int id);
    bool checkIfFlightExist(int id);
    bool createFlight(int id, int cap);
    void getInfo();
};


#endif //CPP3_FLIGHTARRAY_H
