//
// Created by new pc on 23/10/2018.
//

#ifndef CPP3_FLIGHTPOOL_H
#define CPP3_FLIGHTPOOL_H

#include "FlightBooking.h"
#include <map>

class FlightPool {
private:
    FlightBooking arr[10];
    bool empty[10] = {true, true, true, true, true, true, true, true, true, true};
    std::map<int, int> flightPool;
    int inUse = 0;
    int size;
    int arrId;
    int getId();
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
