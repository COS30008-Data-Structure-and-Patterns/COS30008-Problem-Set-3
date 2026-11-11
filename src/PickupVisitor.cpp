#include "../include/PickupVisitor.h"

PickupVisitor::PickupVisitor(List<Item> * inv)
    : inventory(inv) {}

void PickupVisitor::visit(Monster & m) {
    cout << "You cannot pick up a monster (" << m.name << ").\n";
}

void PickupVisitor::visit(Item & i) {
    if ( inventory == nullptr ) {
        cout << "No inventory assigned.\n";
        return;
    }

    inventory->add(i);
    cout << "You picked up: " << i.name << "\n";
}
