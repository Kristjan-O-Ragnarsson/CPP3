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
    } else {
        FlightNode *newNode = new FlightNode(id, n);
        newNode->data.printStatus();
        if(head->data.getId() > id) {
            newNode->next = head;
            head = newNode;
        } else {
            FlightNode *current = head;
            FlightNode *prev = head;
            while (current && current->data.getId() < id) {
                prev = current;
                current = current->next;
            }
            prev->next = newNode;
            newNode->next = current;
        }
    }
}