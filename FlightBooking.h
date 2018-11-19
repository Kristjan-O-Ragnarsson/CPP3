//
// Created by Lenovo on 23.10.2018.
//

#ifndef CPP3_FLIGHTBOOKING_H
#define CPP3_FLIGHTBOOKING_H

#include <string>

class FlightBooking {
public:
    FlightBooking() {};
    FlightBooking(int id, int capacity, int reserved);
    //~FlightBooking();
    std::string printStatus();
    bool addPassengers(int n);
    bool removePassengers(int n);
    int getId();
    friend bool operator> (const FlightBooking& fFlight, const FlightBooking& sFlight);
    friend bool operator< (const FlightBooking& fFlight, const FlightBooking& sFlight) { return sFlight > fFlight;};
    friend bool operator==(const FlightBooking& fFlight, const FlightBooking& sFlight);
    friend bool operator!=(const FlightBooking& fFlight, const FlightBooking& sFlight){ return !(fFlight == sFlight);};
    friend bool operator>=(const FlightBooking& fFlight, const FlightBooking& sFlight){ return !(fFlight < sFlight);};
    friend bool operator<=(const FlightBooking& fFlight, const FlightBooking& sFlight){ return !(fFlight > sFlight);};
private:
    int getFillLevel();
    int id_m;
    int capacity_m;
    int reserved_m;
};

std::ostream& operator<<(std::ostream &, FlightBooking fligh);

#endif //CPP3_FLIGHTBOOKING_H
