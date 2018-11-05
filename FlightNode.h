//
// Created by Lenovo on 5.11.2018.
//

#ifndef CPP3_FLIGHTNODE_H
#define CPP3_FLIGHTNODE_H

#include "FlightBooking.h"

class FlightNode {
public:
    FlightBooking data;
    FlightNode *next;
    FlightNode(int id, int cap);
};
#endif //CPP3_FLIGHTNODE_H
