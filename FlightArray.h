//
// Created by Lenovo on 29.10.2018.
//

#ifndef CPP3_FLIGHTARRAY_H
#define CPP3_FLIGHTARRAY_H

#include "FlightBooking.h"

class FlightArray {
private:
    FlightBooking *fArr;
    int size;
    int index;
public:
    FlightArray();
    ~FlightArray();
    void insertFlight(FlightBooking flight);
};


#endif //CPP3_FLIGHTARRAY_H
