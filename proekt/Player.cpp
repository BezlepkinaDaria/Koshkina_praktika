#include "Player.h"
#include <iostream>
using namespace std;

Player::Player() : health(3) {}

Player::~Player() {
    for (auto item : items) {
        delete item;
    }
}

int Player::getHealth() {
    return health;
}

void Player::changeHealth(int value) {
    health += value;
    if (health > 3) health = 3;
    if (health < 0) health = 0;
}

bool Player::addItem(Item* item) {
    if (items.size() < maxItems) {
        items.push_back(item);
        cout << "[+] Получен предмет: " << item->getName() << endl;
        return true;
    }
    cout << "[!] Инвентарь полон!" << endl;
    return false;
}

void Player::showItems() {
    if (items.empty()) {
        cout << "Инвентарь пуст." << endl;
        return;
    }
    cout << "\n=== ИНВЕНТАРЬ (" << items.size() << "/" << maxItems << ") ===" << endl;
    for (int i = 0; i < items.size(); i++) {
        cout << i + 1 << ". " << items[i]->getName()
            << " - " << items[i]->getDesc() << endl;
    }
    cout << "========================" << endl;
    cout << "Для использования предмета введите его номер: ";

    int itemChoice;
    cin >> itemChoice;

    if (itemChoice >= 1 && itemChoice <= items.size()) {
        items[itemChoice - 1]->use();
    }
    else {
        cout << "Неверный номер предмета." << endl;
    }
}

bool Player::hasItem(string name) {
    for (auto item : items) {
        if (item->getName() == name) {
            return true;
        }
    }
    return false;
}

void Player::useItem(int index) {
    if (index >= 0 && index < items.size()) {
        items[index]->use();
    }
    else {
        cout << "Неверный индекс предмета!" << endl;
    }
}