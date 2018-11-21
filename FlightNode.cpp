//
// Created by Lenovo on 5.11.2018.
//
#include "FlightNode.h"

FlightNode::FlightNode(int id, int cap) {
    data = FlightBooking(id, cap, 0);
    next = nullptr;
}

FlightNode::FlightNode(int id, int cap, int res) {
    data = FlightBooking(id, cap, res);
    next = nullptr;
}
