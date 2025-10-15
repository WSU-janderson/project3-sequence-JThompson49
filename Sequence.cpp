#include "Sequence.h"
#include <iostream>

Sequence::Sequence(size_t sz) {}
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

void Sequence::push_back(std::string item) {}
void Sequence::pop_back() {}
void Sequence::insert(size_t position, std::string item) {}
void Sequence::erase(size_t position) {}
void Sequence::erase(size_t position, size_t count) {}
void Sequence::clear() {}

std::ostream& operator<<(std::ostream& os, const Sequence& s) {
    return os;
}
