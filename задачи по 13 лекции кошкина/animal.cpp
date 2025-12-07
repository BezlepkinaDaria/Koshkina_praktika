#include "animal.h"
using namespace std;

Animal::Animal() : name("Неизвестно"), species("Неизвестно"), color("Неизвестно"), age(0), weight(0.0) {}

Animal::Animal(string n, string s, string c, int a, double w) {
    setAnimalData(n, s, c, a, w);
}

void Animal::setAnimalData(string n, string s, string c, int a, double w) {
    setName(n);
    setSpecies(s);
    setColor(c);
    setAge(a);
    setWeight(w);
}

void Animal::setName(string n) {
    if (n.empty()) {
        cout << "Ошибка: Имя не может быть пустым!" << endl;
        return;
    }
    name = n;
}

void Animal::setSpecies(string s) {
    if (s.empty()) {
        cout << "Ошибка: Вид не может быть пустым!" << endl;
        return;
    }
    species = s;
}

void Animal::setColor(string c) {
    if (c.empty()) {
        cout << "Ошибка: Окрас не может быть пустым!" << endl;
        return;
    }
    color = c;
}

void Animal::setAge(int a) {
    if (a < 0) {
        cout << "Ошибка: Возраст не может быть отрицательным!" << endl;
        return;
    }
    age = a;
}

void Animal::setWeight(double w) {
    if (w < 0) {
        cout << "Ошибка: Вес не может быть отрицательным!" << endl;
        return;
    }
    weight = w;
}

string Animal::getName() const { return name; }
string Animal::getSpecies() const { return species; }
string Animal::getColor() const { return color; }
int Animal::getAge() const { return age; }
double Animal::getWeight() const { return weight; }

void Animal::increaseWeight(int days) {
    if (days < 0) {
        cout << "Ошибка: Количество дней не может быть отрицательным!" << endl;
        return;
    }
    double weightIncrease = weight * 0.01 * days;
    weight += weightIncrease;
    cout << "Вес увеличен на " << weightIncrease << " кг после " << days << " дней кормежки." << endl;
    cout << "Новый вес: " << weight << " кг" << endl;
}

void Animal::changeName(string newName) {
    if (newName.empty()) {
        cout << "Ошибка: Новое имя не может быть пустым!" << endl;
        return;
    }
    cout << "Имя изменено с '" << name << "' на '" << newName << "'" << endl;
    name = newName;
}

void Animal::displayInfo() const {
    cout << "=== Информация о животном ===" << endl;
    cout << "Имя: " << name << endl;
    cout << "Вид: " << species << endl;
    cout << "Окрас: " << color << endl;
    cout << "Возраст: " << age << " лет" << endl;
    cout << "Вес: " << weight << " кг" << endl;
    cout << "==============================" << endl;
}