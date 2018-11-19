//
// Created by new pc on 23/10/2018.
//

#ifndef CPP3_FLIGHTPOOL_H
#define CPP3_FLIGHTPOOL_H

#include "FlightBooking.h"
#include "FlightArray.h"

class FlightPool {
private:
    FlightArray fArr;
    FlightBooking tmp;
public:
    FlightPool();
    ~FlightPool();
    bool checkIfFlightExist(int id);
    //FlightBooking addFlight();
    bool createFlight(int id, int cap);
    bool removePassengers(int id, int n);
    bool deletFlight(int id);
    bool addPassengers(int id, int n);
    void printStatus(int id);
};

#endif //CPP3_FLIGHTPOOL_H
