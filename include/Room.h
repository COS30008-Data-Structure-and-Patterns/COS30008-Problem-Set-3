#pragma once

#include <string>
#include <vector>
#include <iostream>
#include "Monster.h"
#include "Item.h"
#include "List.h"

using namespace std;

class Room {
public:
    string name;
    string description;

    vector<Monster> monsters;
    List<Item> items;

    Room();
    Room(const string & n, const string & d);

    void addMonster(const Monster & m);
    void addItem(const Item & i);

    void displayContents() const;
};
