#include "Sequence.h"
#include <iostream>

Sequence::Sequence(size_t sz) : head(nullptr), tail(nullptr), numElts(0) {
    for (size_t i = 0; i < sz; ++i) {
        SequenceNode* newNode = new SequenceNode("");
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        ++numElts;
    }
}
Sequence::Sequence(const Sequence& s) {}
Sequence::~Sequence() {}
Sequence& Sequence::operator=(const Sequence& s) { return *this; }



std::string& Sequence::operator[](size_t position) {
    if (position >= numElts) {
        throw std::out_of_range("Index out of bounds");
    }

    // Go to the target node
    SequenceNode* current = head;
    for (size_t i = 0; i < position; ++i) {
        current = current->next;
    }

    // Returns the reference of the item
    return current->item;

}
std::string Sequence::front() const { return ""; }
std::string Sequence::back() const { return ""; }

bool Sequence::empty() const { return true; }
size_t Sequence::size() const { return 0; }

void Sequence::push_back(std::string item) {
    SequenceNode* newNode = new SequenceNode(item);

    if (!head) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    ++numElts;
}

void Sequence::pop_back() {
    if (!tail) return;  // Empty
    SequenceNode* toDelete = tail;

    if (head == tail) {
        head = tail = nullptr;
    } else {
        tail = tail->prev;
        tail->next = nullptr;
    }
    delete toDelete;
    --numElts;
}
void Sequence::insert(size_t position, std::string item) {}
void Sequence::erase(size_t position) {}
void Sequence::erase(size_t position, size_t count) {}
void Sequence::clear() {}

std::ostream& operator<<(std::ostream& os, const Sequence& s) {
    os << "<";
    SequenceNode* current = s.head;
    while (current) {
        os << current->item;
        if (current->next) os << ", ";
        current = current->next;
    }
    os << ">";
    return os;
}
