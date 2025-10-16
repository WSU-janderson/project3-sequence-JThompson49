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
    seq.push_back("D");
    std::cout << "After push_back:  " << seq << std::endl;
    return 0;
}