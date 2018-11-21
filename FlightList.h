//
// Created by Lenovo on 5.11.2018.
//

#ifndef CPP3_FLIGHTLIST_H
#define CPP3_FLIGHTLIST_H

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "FlightNode.h"

class FlightList {
private:
    FlightNode *head;
public:
   FlightList();
   bool checkIfFlightExist(int id);
   bool createFlight(int id,int n);
   bool createFlight(int id,int n, int cap);
   bool deletFlight(int id);
   bool addPassengers(int id,int n);
   bool removePassengers(int id,int n);
   void printStatus(int id);
   void getInfo();
   void printAll();
   void saveAll();
};

#endif //CPP3_FLIGHTLIST_H
