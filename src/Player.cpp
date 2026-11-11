#include "../include/Player.h"

Player::Player(string n, int hp, int a)
    : name(n), hp(hp), maxhp(hp), attackPower(a) {}

string Player::getName() {
    return name;
}

int Player::getHP() {
    return hp;
}

int Player::getMaxHP() {
    return maxhp;
}

int Player::getAttackPower() {
    return attackPower;
}

void Player::setHP(int h) {
    if ( h < 0 ) h = 0;
    else if ( h > maxhp ) h = maxhp;
    else hp = h;
}

bool Player::isAlive() const {
    return hp > 0;
}

void Player::displayInventory() const {
    cout << "== Inventory (" << inventory.getSize() << ") ==\n";

    if ( inventory.getSize() == 0 ) {
        cout << "  (empty)\n";
    } else {
        for ( int i = 0; i < inventory.getSize(); i++ ) {
            try {
                const Item & it = inventory[i];
                cout << "  [" << i << "] " << it.name
                    << " - " << it.description << "\n";
            } catch ( ... ) {}
        }
    }

    cout << "========================\n";
}

string Player::ShowPlayerHP() {
    const int BAR_LENGTH = 20;
    int filled = (int) ((double) hp / maxhp * BAR_LENGTH);
    int empty = BAR_LENGTH - filled;
    string bar = "[";
    bar += string(filled, '|');
    bar += string(empty, '.');
    bar += "]";

    return bar;
}

string Player::PrintPlayer() {
    string result = "Player: " + name + "\n";
    result += "HP: " + to_string(hp) + "/" + to_string(maxhp) + "\n";
    result += ShowPlayerHP() + "\n";
    result += "Attack Power: " + to_string(attackPower) + "\n";
    result += "Inventory Size: " + to_string(inventory.getSize()) + "\n";
    return result;
}

ostream & operator<<(ostream & s, Player & p) {
    s << p.PrintPlayer();
    return s;
}