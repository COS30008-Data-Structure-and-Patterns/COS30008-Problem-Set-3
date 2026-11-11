#pragma once

class Monster;
class Item;

class Visitor {
public:
    virtual ~Visitor() {}

    virtual void visit(Monster & m) = 0;
    virtual void visit(Item & i) = 0;
};
