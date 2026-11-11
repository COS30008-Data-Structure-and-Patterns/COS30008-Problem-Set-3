#pragma once

#include <string>
#include <iostream>
#include "List.h"
#include "Item.h"

using namespace std;

class Player {
private:
    string name;
    int maxhp;
    int attackPower;

public:
    int hp;

    List<Item> inventory;

    Player(string n, int hp, int a);

    // Getters
    string getName();
    int getHP();
    int getMaxHP();
    int getAttackPower();

    // Setters
    void setHP(int h);

    bool isAlive() const;

    void displayInventory() const;

    string ShowPlayerHP();
    string PrintPlayer();

    friend ostream & operator<<(ostream & s, Player & p);
};