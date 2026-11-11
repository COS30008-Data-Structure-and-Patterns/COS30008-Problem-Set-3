#include "../include/Dungeon.h"

Dungeon::Dungeon() {
    root = nullptr;
}

Dungeon::~Dungeon() {
    if ( root != nullptr ) {
        delete root;
        root = nullptr;
    }
}

DungeonNode * Dungeon::getRoot() const {
    return root;
}

// Returns indices of non-empty children
vector<int> Dungeon::listAvailableChildIndices(DungeonNode * node) const {
    vector<int> results;

    for ( int i = 0; i < 4; i++ ) {
        try {
            DungeonNode & child = (*node)[i];
            if ( !child.isEmpty() ) {
                results.push_back(i);
            }
        } catch ( ... ) {
            // ignore invalid index
        }
    }
    return results;
}

// Build the actual sample dungeon structure
DungeonNode * Dungeon::buildSampleDungeon() {

    root = new DungeonNode(Room("Entrance", "A dusty dungeon entrance."));
    root->getKey().addMonster(Monster("Goblin Scout", 8, 2));
    root->getKey().addItem(Item("Rusty Dagger", "A dull, rusty blade."));

    // Hallway
    DungeonNode * hall = new DungeonNode(Room("Hallway", "A long hallway with torchlights."));
    hall->getKey().addMonster(Monster("Skeleton", 12, 3));
    hall->getKey().addItem(Item("Health Potion", "Restores 10 HP."));

    // Armory
    DungeonNode * armory = new DungeonNode(Room("Armory", "Old racks of broken weapons."));
    armory->getKey().addMonster(Monster("Armored Rat", 6, 1));
    armory->getKey().addItem(Item("Short Sword", "A sturdier weapon."));

    // Chamber
    DungeonNode * chamber = new DungeonNode(Room("Chamber", "A grand stone chamber with pillars."));
    chamber->getKey().addMonster(Monster("Orc Brute", 20, 5));
    chamber->getKey().addItem(Item("Gold Coin", "Shiny and valuable."));

    // Alcove
    DungeonNode * alcove = new DungeonNode(Room("Hidden Alcove", "A tiny hidden room."));
    alcove->getKey().addItem(Item("Gemstone", "A precious gem."));

    // Build tree connections
    root->attachTree(0, hall);
    root->attachTree(1, armory);

    hall->attachTree(0, chamber);
    armory->attachTree(2, alcove);

    return root;
}
