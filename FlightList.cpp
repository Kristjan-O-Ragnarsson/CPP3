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
        head->data.printStatus();
        return true;
    } else {
        FlightNode *newNode = new FlightNode(id, n);
        newNode->data.printStatus();
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
    current->data.printStatus();
}

void FlightList::printAll() {
    FlightNode *current = head;
    while (current){
        current->data.printStatus();
        current = current->next;
    }

}

void FlightList::getInfo() {
    return;
}