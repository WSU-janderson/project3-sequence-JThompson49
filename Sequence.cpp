#include "Sequence.h"
#include <iostream>




/**
 * Sequence(size_t sz)
 * Purpose: Constructs a Sequence with a number of empty nodes.
 * Parameters: sz — which is the number of nodes to create.
 * Return: None.
 * Side effects: Allocates memory.
 */
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

/**
 * Sequence(const Sequence& s)
 * Purpose: Makes a deep copy.
 * Parameters: s — the Sequence to copy.
 * Return: None.
 * Side effects: Allocates memory and copies content.
 */
Sequence::Sequence(const Sequence& s): head(nullptr), tail(nullptr), numElts(0) {
    SequenceNode* current = s.head;
    while (current) {
        push_back(current->item);
        current = current->next;
    }
}

/**
 * ~Sequence()
 * Purpose: Destructor.
 * Parameters: None.
 * Return: None.
 * Side effects: Deletes all nodes.
 */
Sequence::~Sequence() {
    clear();
}

/**
 * operator=(const Sequence& s)
 * Purpose: Assigns one Sequence to another.
 * Parameters: s — the Sequence to copy from.
 * Return: The current Sequence.
 * Side effects: Deletes nodes and makes new ones.
 */
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

/**
 * operator[](size_t position)
 * Purpose: Gets the item at the position.
 * Parameters: position — index of the item.
 * Return: Reference of string at that index.
 * Side effects: Throws out_of_range if position is invalid.
 */
std::string& Sequence::operator[](size_t position) {
    if (position >= numElts) {
        throw std::out_of_range("out of bounds");
    }

    // Go to the target node
    SequenceNode* current = head;
    for (size_t i = 0; i < position; ++i) {
        current = current->next;
    }

    // Returns the reference of the item
    return current->item;

}

/**
 * front() const
 * Purpose: Returns the first item.
 * Parameters: None.
 * Return: Copy of first string.
 * Side effects: Throws out_of_range if Sequence is empty.
 */
std::string Sequence::front() const {
    if (!head) {
        throw std::out_of_range("Empty Sequence");
    }
    return head->item;
}

/**
 * back() const
 * Purpose: Returns the last item.
 * Parameters: None.
 * Return: Copy of last string.
 * Side effects: Throws out_of_range if Sequence is empty.
 */
std::string Sequence::back() const {
    if (!tail) {
        throw std::out_of_range("Empty Sequence");
    }
    return tail->item;
}

/**
 * empty() const
 * Purpose: Checks if empty.
 * Parameters: None.
 * Return: True if Sequence is empty, false otherwise.
 * Side effects: None.
 */
bool Sequence::empty() const { return numElts == 0; }

/**
 * size() const
 * Purpose: Returns the number of elements.
 * Parameters: None.
 * Return: Number of elements.
 * Side effects: None.
 */
size_t Sequence::size() const { return numElts; }

/**
 * push_back(std::string item)
 * Purpose: Adds a new item to the end of Sequence.
 * Parameters: item — string to add.
 * Return: None.
 * Side effects: Makes a new node and changes tail and numElts.
 */
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

/**
 * pop_back()
 * Purpose: Removes the last item.
 * Parameters: None.
 * Return: None.
 * Side effects: Deletes the last node and changes tail and numElts.
 */
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

/**
 * insert(size_t position, std::string item)
 * Purpose: Inserts an item at the wanted index.
 * Parameters: position — index to insert at, item — string to insert.
 * Return: None.
 * Side effects: Creates a new node and changes links and numElts.
 * Throws: out_of_range if position is invalid.
 */
void Sequence::insert(size_t position, std::string item) {
    if (position > numElts) {
        throw std::out_of_range("out of bounds");
    }

    if (position == numElts) {
        push_back(item);
        return;
    }

    SequenceNode* newNode = new SequenceNode(item);

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

/**
 * erase(size_t position)
 * Purpose: Removes the item at the wanted index.
 * Parameters: position — index of the item.
 * Return: None.
 * Side effects: Deletes one node and changes links and numElts.
 * Throws: out_of_range if position is invalid.
 */
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

/**
 * erase(size_t position, size_t count)
 * Purpose: Removes multiple items starting at wanted index.
 * Parameters: position — starting index, count — number of items to remove.
 * Return: None.
 * Side effects: Deletes multiple nodes and changes links and numElts.
 * Throws: out_of_range if position is invalid.
 */
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

/**
 * clear()
 * Purpose: Removes all items.
 * Parameters: None.
 * Return: None.
 * Side effects: Deletes all nodes and resets head, tail, and numElts.
 */
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

/**
 * operator<<(std::ostream& os, const Sequence& s)
 * Purpose: Outputs Sequence to a stream.
 * Parameters: os — output stream, s — Sequence to print.
 * Return: Reference of output stream.
 * Side effects: None.
 */
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
