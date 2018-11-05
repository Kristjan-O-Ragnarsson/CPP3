//
// Created by Lenovo on 5.11.2018.
//

#ifndef CPP3_FLIGHTLIST_H
#define CPP3_FLIGHTLIST_H

#include "FlightNode.h"

class FlightList {
private:
    FlightNode *head;
public:
   FlightList();
   bool checkIfFlightExist(int id);
   bool createFlight(int id,int n);
   bool deletFlight(int id);
   bool addPassengers(int id,int n);
   bool removePassengers(int id,int n);
   void printStatus(int id);
   void getInfo();
   void printAll();
};

#endif //CPP3_FLIGHTLIST_H
