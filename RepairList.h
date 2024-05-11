#ifndef REPAIRLIST_H
#define REPAIRLIST_H

#include "Repair.h"

class RepairList {
private:
    class Node {
    public:
        Repair* data;
        Node* next;
        explicit Node(Repair* data, Node* next = nullptr) : data(data), next(next) {}
    };

    Node* head;
    Node* tail;

public:
    RepairList();
    ~RepairList();
    void add(Repair* repair);
    bool isEmpty() const;
    int size() const;
    void print() const;
    Repair* getNext();
};

#endif // REPAIRLIST_H
