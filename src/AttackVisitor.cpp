#include "../include/AttackVisitor.h"

AttackVisitor::AttackVisitor(int p)
    : attackerPower(p) {}

void AttackVisitor::visit(Monster & m) {
    if ( !m.isAlive() ) {
        cout << "You attack " << m.name << " but it is already dead.\n";
        return;
    }

    m.hp -= attackerPower;
    cout << "You deal " << attackerPower << " damage to " << m.name << ". ";

    if ( m.hp <= 0 ) {
        cout << m.name << " has died.\n";
    } else {
        cout << m.name << " has " << m.hp << " HP left.\n";
    }
}

void AttackVisitor::visit(Item & i) {
    cout << "Attacking item '" << i.name << "' does nothing.\n";
}
