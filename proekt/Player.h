#pragma once
#include "Item.h"
#include <vector>
#include <string>
using namespace std;

class Player {
private:
    int health;
    vector<Item*> items;
    const int maxItems = 5;
public:
    Player();
    ~Player();
    int getHealth();
    void changeHealth(int value);
    bool addItem(Item* item);
    void showItems();
    bool hasItem(string name);
    void useItem(int index);
};