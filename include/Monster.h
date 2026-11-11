#pragma once

#include <string>
#include <iostream>
#include "Visitor.h"

using namespace std;

class Monster {
public:
    string name;
    int hp;
    int attackPower;

    Monster(const string & n, int h, int ap);

    bool isAlive() const;

    void accept(Visitor & v);   // Single accept using Visitor parent
};
