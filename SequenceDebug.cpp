/**
 * SequenceDebug.cpp
 * Project 3
 * CS 3100
 *
 * In this file, you will write your tests as you implement Sequence. If you are using CLion, you need to select
 * SequenceDebug from the drop-down menu next to the Build (hammer icon) if it is on SequenceTestHarness
 */
#include <iostream>
#include <sstream>
#include "Sequence.h"

using namespace std;

int main() {
    Sequence seq(3);
    seq[0] = "A";
    seq[1] = "B";
    seq[2] = "C";

    std::cout << "Start: " << seq << std::endl;
    std::cout << "Size: " << seq.size() << std::endl;
    std::cout << "Front: " << seq.front() << std::endl;
    std::cout << "Back: " << seq.back() << std::endl;

    seq.push_back("D");
    std::cout << "After push_back:  " << seq << std::endl;
    std::cout << "Size: " << seq.size() << std::endl;

    seq.pop_back();
    std::cout << "After pop_back:  " << seq << std::endl;
    std::cout << "Size: " << seq.size() << std::endl;

    seq.insert(2,"F");
    std::cout << "After F Insert:  " << seq << std::endl;
    std::cout << "Size: " << seq.size() << std::endl;

    seq.erase(2);
    std::cout << "After erase pos 2:  " << seq << std::endl;
    std::cout << "Size: " << seq.size() << std::endl;

    seq.push_back("D");
    seq.push_back("E");
    seq.push_back("F");
    seq.push_back("G");
    seq.push_back("H");
    std::cout << "After major push_back:  " << seq << std::endl;

    Sequence copy = seq;
    std::cout << "Deep copy of sequence:  " << seq << std::endl;

    Sequence seq3(3);
    seq3[0] = "A";
    seq3[1] = "B";

    seq3 = seq;

    std::cout << "After seq3 = seq:  " << seq3 << std::endl;

    seq.erase(2,3);
    std::cout << "After erasev2 2,3:  " << seq << std::endl;
    std::cout << "Size: " << seq.size() << std::endl;

    seq.clear();
    std::cout << "After clear:  " << seq << std::endl;
    std::cout << "Size: " << seq.size() << std::endl;

    //Error checks
    Sequence seq2(0);
    std::cout << "Size: " << seq2.size() << std::endl;
    //std::cout << "Front: " << seq2.front() << std::endl;
    //std::cout << "Back: " << seq2.back() << std::endl;
    //seq2.pop_back();
    //seq2.insert(2,"F");
    //seq2.erase(2);
    //seq2.erase(2,3);

    return 0;
}