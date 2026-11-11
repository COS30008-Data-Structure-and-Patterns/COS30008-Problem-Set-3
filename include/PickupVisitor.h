#pragma once

#include <iostream>
#include "Visitor.h"
#include "Item.h"
#include "Monster.h"
#include "List.h"

using namespace std;

class PickupVisitor : public Visitor {
public:
    List<Item> * inventory;

    PickupVisitor(List<Item> * inv = nullptr);

    void visit(Monster & m) override;  // cannot pick up monster
    void visit(Item & i) override;     // pick up item
};
