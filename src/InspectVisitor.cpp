#include "../include/InspectVisitor.h"

void InspectVisitor::visit(Monster & m) {
    cout << "Inspect Monster -- Name: " << m.name
        << ", HP: " << m.hp
        << ", Attack: " << m.attackPower << "\n";
}

void InspectVisitor::visit(Item & i) {
    cout << "Inspect Item -- Name: " << i.name
        << ", Description: " << i.description << "\n";
}
