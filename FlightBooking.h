//
// Created by Lenovo on 23.10.2018.
//

#ifndef CPP3_FLIGHTBOOKING_H
#define CPP3_FLIGHTBOOKING_H

class FlightBooking {
public:
    FlightBooking(int id, int capacity, int reserved);
    //~FlightBooking();
    void printStatus();
    bool addPassengers(int n);
    bool removePassengers(int n);
private:
    int getFillLevel();
    int id_m;
    int capacity_m;
    int reserved_m;
};


#endif //CPP3_FLIGHTBOOKING_H
