// intlist.cpp
// Implements class IntList
// Satvik Talchuru, 10/28/2024

#include "intlist.h"

#include <iostream>
using std::cout;

// Copy constructor
IntList::IntList(const IntList& source) {
    if (!source.first){
        first = nullptr;
    } 
    else {
        first = new Node;
        first->info = source.first->info;

        Node* current = first;
        Node* sourceCurrent = source.first-> next;

        while (sourceCurrent != nullptr) {
            current->next = new Node;
            current = current->next;
            current->info = sourceCurrent->info;

            sourceCurrent = sourceCurrent->next;
        }
        current->next = nullptr;
    }
}

// Destructor deletes all nodes
IntList::~IntList() {
    Node* current = first;

    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    first = nullptr;
}

// Return sum of values in list
int IntList::sum() const {
    int total = 0;
    Node* n = first;

    while (n) {
        total += n->info;
        n = n->next;
    }
    return total;
}

// Returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    Node* n = first;

    while (n) {
        if (n->info == value) {
            return true;
        }
        n = n->next;
    }
    return false;
}

// Returns maximum value in list, or 0 if empty list
int IntList::max() const {
    if (first == nullptr) {
        return 0;
    }

    int maxValue = first->info;
    Node* n = first->next;

    while (n) {
        if (n->info > maxValue) {
            maxValue = n->info;
        }
        n = n->next;
    }

    return maxValue;
}

// Returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    if (first == nullptr) {
        return 0;
    }

    int total = sum();
    int num = count();
    return total / (num + 0.0);
}

// Inserts value as new node at beginning of list
void IntList::insertFirst(int value) {
    Node* newNode = new Node;
    newNode->info = value;
    newNode->next = first;
    first = newNode;
}

// Assignment operator should copy the list from the source
// to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    // IMPLEMENT
    return *this;
}


// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// Constructor sets up empty list
IntList::IntList() : first(nullptr) { }

// Append value at end of list
void IntList::append(int value) {
    if (first == nullptr) { // Empty list
        first = new Node;
        first->info = value;
        first->next = nullptr;
    } else {
        Node *n = first;
        while (n->next) // Not last node yet
            n = n->next;

        n->next = new Node;
        n->next->info = value;
        n->next->next = nullptr;
    }
}

// Print values enclose in [], separated by spaces
void IntList::print() const {
    Node* n = first;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

// Return count of values
int IntList::count() const {
    int result = 0;
    Node* n = first;
    while (n) {
        ++result;
        n = n->next;
    }

    return result;
}
