#pragma once

#include <iostream>
#include "Visitor.h"
#include "Monster.h"
#include "Item.h"

using namespace std;

class InspectVisitor : public Visitor {
public:
    InspectVisitor() {}

    void visit(Monster & m) override;
    void visit(Item & i) override;
};
