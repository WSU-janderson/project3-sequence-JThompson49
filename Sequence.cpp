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
//Deep copy
Sequence::Sequence(const Sequence& s): head(nullptr), tail(nullptr), numElts(0) {
    SequenceNode* current = s.head;
    while (current) {
        push_back(current->item);
        current = current->next;
    }
}
Sequence::~Sequence() {
    clear();
}

Sequence& Sequence::operator=(const Sequence& s) {
    if (this == &s) {
        return *this;
    }
    clear();

    SequenceNode* current = s.head;
    while (current) {
        push_back(current->item);
        current = current->next;
    }
    return *this;
}

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
std::string Sequence::front() const {
    if (!head) {
        throw std::out_of_range("Empty Sequence");
    }
    return head->item;
}
std::string Sequence::back() const {
    if (!tail) {
        throw std::out_of_range("Empty Sequence");
    }
    return tail->item;
}

bool Sequence::empty() const { return true; }
size_t Sequence::size() const { return numElts; }

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

void Sequence::insert(size_t position, std::string item) {
    if (position > numElts) {
        throw std::out_of_range("out of bounds");
    }

    SequenceNode* newNode = new SequenceNode(item);

    if (position == numElts) {
        push_back(item);
        delete newNode;
        return;
    }

    //Go to where insert is needed
    SequenceNode* current = head;
    for (size_t i = 0; i < position; ++i) {
        current = current->next;
    }

    newNode->next = current;
    newNode->prev = current->prev;

    if (current->prev) {
        current->prev->next = newNode;
    } else {
        head = newNode;
    }
    current->prev = newNode;
    ++numElts;
}

void Sequence::erase(size_t position) {
    if (position >= numElts) {
        throw std::out_of_range("out of bounds");
    }

    SequenceNode* current = head;
    for (size_t i = 0; i < position; ++i) {
        current = current->next;
    }

    if (current->prev) {
        current->prev->next = current->next;
    } else {
        head = current->next;  // Erase head
    }

    if (current->next) {
        current->next->prev = current->prev;
    } else {
        tail = current->prev;  // Erase tail
    }
    delete current;
    --numElts;
}
void Sequence::erase(size_t position, size_t count) {
    if (position >= numElts || count == 0 || position + count > numElts) {
        throw std::out_of_range("out of bounds");
    }

    SequenceNode* current = head;
    for (size_t i = 0; i < position; ++i) {
        current = current->next;
    }

    for (size_t i = 0; i < count; ++i) {
        SequenceNode* toDelete = current;
        current = current->next;

        if (toDelete->prev) {
            toDelete->prev->next = toDelete->next;
        } else {
            head = toDelete->next;
        }

        if (toDelete->next) {
            toDelete->next->prev = toDelete->prev;
        } else {
            tail = toDelete->prev;
        }
        delete toDelete;
        --numElts;
    }
}

void Sequence::clear() {
    SequenceNode* current = head;
    while (current) {
        SequenceNode* next = current->next;
        delete current;
        current = next;
    }
    head = tail = nullptr;
    numElts = 0;
}

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
