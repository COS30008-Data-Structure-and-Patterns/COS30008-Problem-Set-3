#pragma once

#include <iostream>
#include "Visitor.h"
#include "Monster.h"
#include "Item.h"

using namespace std;

class AttackVisitor : public Visitor {
public:
    int attackerPower;

    AttackVisitor(int p = 1);

    void visit(Monster & m) override;
    void visit(Item & i) override;
};
