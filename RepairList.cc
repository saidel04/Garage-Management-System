#include "RepairList.h"
#include <iostream>

RepairList::RepairList() : head(nullptr), tail(nullptr) {}

RepairList::~RepairList() {
    Node* current = head;
    while (current != nullptr) {
        Node* toDelete = current;
        current = current->next;
        delete toDelete->data; 
        delete toDelete;
    }
}

void RepairList::add(Repair* repair) {
    Node* newNode = new Node(repair);
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

bool RepairList::isEmpty() const {
    return head == nullptr;
}

int RepairList::size() const {
    int count = 0;
    Node* current = head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

void RepairList::print() const {
    Node* current = head;
    while (current != nullptr) {
        current->data->print();
        current = current->next;
    }
}

Repair* RepairList::getNext() {
    if (head == nullptr) return nullptr;
    Node* nodeToRemove = head;
    Repair* repair = nodeToRemove->data;
    head = head->next;
    if (head == nullptr) {
        tail = nullptr;
    }
    delete nodeToRemove;
    return repair;
}
