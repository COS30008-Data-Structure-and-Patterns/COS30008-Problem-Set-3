#pragma once

#include <string>
#include <iostream>
#include "Visitor.h"

using namespace std;

class Item {
public:
    string name;
    string description;

    Item();
    Item(const string & n, const string & d);

    void accept(Visitor & v);   // Single accept
};
