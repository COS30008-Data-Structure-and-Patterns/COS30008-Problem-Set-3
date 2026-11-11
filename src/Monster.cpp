#include "../include/Monster.h"
#include "../include/Visitor.h"

Monster::Monster(const string & n, int h, int ap)
    : name(n), hp(h), attackPower(ap) {}

bool Monster::isAlive() const {
    return hp > 0;
}

void Monster::accept(Visitor & v) {
    v.visit(*this);
}
