#include "../include/Room.h"

Room::Room()
    : name("Empty"), description("An empty place.") {}

Room::Room(const string & n, const string & d)
    : name(n), description(d) {}

void Room::addMonster(const Monster & m) {
    monsters.push_back(m);
}

void Room::addItem(const Item & i) {
    items.add(i);
}

void Room::displayContents() const {
    cout << "--- " << name << " ---\n";
    cout << description << "\n\n";

    // Show monsters
    if ( monsters.empty() ) {
        cout << "No monsters here.\n";
    } else {
        cout << "Monsters:\n";
        for ( size_t i = 0; i < monsters.size(); i++ ) {
            cout << "  [" << i << "] " << monsters[i].name
                << " (HP: " << monsters[i].hp << ")\n";
        }
    }

    // Show items
    if ( items.getSize() == 0 ) {
        cout << "No items here.\n";
    } else {
        cout << "Items:\n";
        for ( int i = 0; i < items.getSize(); i++ ) {
            try {
                const Item & it = items[i];
                cout << "  [" << i << "] " << it.name << "\n";
            } catch ( ... ) {}
        }
    }

    cout << "\n";
}
