#pragma once

#include <vector>
#include <iostream>
#include "Tree.h"
#include "Room.h"

using namespace std;

// Dungeon using Tree<Room, 4> � four exits per room
typedef Tree<Room, 4> DungeonNode;

class Dungeon {
private:
    DungeonNode * root;

public:
    Dungeon();
    ~Dungeon();

    DungeonNode * getRoot() const;

    DungeonNode * buildSampleDungeon();

    vector<int> listAvailableChildIndices(DungeonNode * node) const;
};
