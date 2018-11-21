//
// Created by Lenovo on 5.11.2018.
//

#include "FlightList.h"

FlightList::FlightList() {
    head = nullptr;
}

bool FlightList::checkIfFlightExist(int id) {
    FlightNode *current = head;
    while(current){
        if(current->data.getId() == id){
            return true;
        }
        current = current->next;
    }
    return false;
}

bool FlightList::createFlight(int id, int n) {
    if(checkIfFlightExist(id)) return false;
    if(head == nullptr) {
        head = new FlightNode(id, n);
        std::cout << head->data;
        return true;
    } else {
        FlightNode *newNode = new FlightNode(id, n);
        std::cout << newNode->data;
        if(head->data.getId() > id) {
            newNode->next = head;
            head = newNode;
            return true;
        } else {
            FlightNode *current = head;
            FlightNode *prev = head;
            while (current && current->data.getId() < id) {
                prev = current;
                current = current->next;
            }
            prev->next = newNode;
            newNode->next = current;
            return true;
        }
    }
}

bool FlightList::createFlight(int id, int n, int cap) {
    if(checkIfFlightExist(id)) return false;
    if(head == nullptr) {
        head = new FlightNode(id, n, cap);
        std::cout << head->data;
        return true;
    } else {
        FlightNode *newNode = new FlightNode(id, n, cap);
        std::cout << newNode->data;
        if(head->data.getId() > id) {
            newNode->next = head;
            head = newNode;
            return true;
        } else {
            FlightNode *current = head;
            FlightNode *prev = head;
            while (current && current->data.getId() < id) {
                prev = current;
                current = current->next;
            }
            prev->next = newNode;
            newNode->next = current;
            return true;
        }
    }
}

bool FlightList::deletFlight(int id) {
    if(!checkIfFlightExist(id)) return false;
    if (head->data.getId() == id) {
        FlightNode *tmp;
        tmp = head->next;
        delete head;
        head = tmp;
        return true;
    } else {
        FlightNode *current = head;
        FlightNode *prev = head;
        while (current->data.getId() != id){
            prev = current;
            current = current->next;
        }
        prev->next = current->next;
        delete current;
    }
}

bool FlightList::addPassengers(int id, int n) {
    if(!checkIfFlightExist(id)) return false;
    FlightNode *current = head;
    while (current->data.getId() != id){
        current = current->next;
    }
    return current->data.addPassengers(n);
}

bool FlightList::removePassengers(int id, int n) {
    if(!checkIfFlightExist(id)) return false;
    FlightNode *current = head;
    while (current->data.getId() != id){
        current = current->next;
    }
    return current->data.removePassengers(n);
}

void FlightList::printStatus(int id) {
    if(!checkIfFlightExist(id)) return;
    FlightNode *current = head;
    while (current->data.getId() != id){
        current = current->next;
    }
    std::cout << current->data;
}

void FlightList::printAll() {
    FlightNode *current = head;
    while (current){
        std::cout << current->data;
        current = current->next;
    }

}

void FlightList::getInfo() {
    return;
}

void FlightList::saveAll() {
    std::fstream data("flights.bin", std::fstream::in | std::fstream::out | std::fstream::binary | std::fstream::trunc);
    FlightBooking fl[2];
    FlightBooking tmp_;
    int tel = 0;
    if(!data.is_open()) "Error!\n";
    else{
        FlightNode *tmp = head;
        while (tmp){
            data.write((char*)&tmp->data, sizeof(FlightBooking));
            tmp=tmp->next;
        }
        data.seekg(0);
        /*
        while (data.read((char*)&tmp_, sizeof(FlightBooking))){
            fl[tel++] = tmp_;
        }
        for(int j = 0; j < 2; j++){
            std::cout << fl[j];
        }
         */
        data.close();
    }

}