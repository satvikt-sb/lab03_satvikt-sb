// intlist.cpp
// Implements class IntList
// YOUR NAME(S), AND DATE

#include "intlist.h"

#include <iostream>
using std::cout;

// Copy constructor
IntList::IntList(const IntList& source) {
    // IMPLEMENT THIS
}

// Destructor deletes all nodes
IntList::~IntList() {
    // IMPLEMENT THIS
}

// Return sum of values in list
int IntList::sum() const {
    return 0; // REPLACE THIS NON-SOLUTION
}

// Returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    return false; // REPLACE THIS NON-SOLUTION
}

// Returns maximum value in list, or 0 if empty list
int IntList::max() const {
    return 0; // REPLACE THIS NON-SOLUTION
}

// Returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    return 0.0; // REPLACE THIS NON-SOLUTION
}

// Inserts value as new node at beginning of list
void IntList::insertFirst(int value) {
    // IMPLEMENT
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
