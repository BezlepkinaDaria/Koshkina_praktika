#include "car.h"
using namespace std;

Car::Car() : brand("Неизвестно"), color("Неизвестно"), bodyType("Неизвестно"), engineVolume(0.0), mileage(0.0) {}

Car::Car(string b, string c, string bt, double ev, double m) {
    setCarData(b, c, bt, ev, m);
}

void Car::setCarData(string b, string c, string bt, double ev, double m) {
    setBrand(b);
    setColor(c);
    setBodyType(bt);
    setEngineVolume(ev);
    setMileage(m);
}

void Car::setBrand(string b) {
    if (b.empty()) {
        cout << "Ошибка: Марка не может быть пустой!" << endl;
        return;
    }
    brand = b;
}

void Car::setColor(string c) {
    if (c.empty()) {
        cout << "Ошибка: Цвет не может быть пустым!" << endl;
        return;
    }
    color = c;
}

void Car::setBodyType(string bt) {
    if (bt.empty()) {
        cout << "Ошибка: Тип кузова не может быть пустым!" << endl;
        return;
    }
    bodyType = bt;
}

void Car::setEngineVolume(double ev) {
    if (ev <= 0) {
        cout << "Ошибка: Объем двигателя должен быть положительным!" << endl;
        return;
    }
    engineVolume = ev;
}

void Car::setMileage(double m) {
    if (m < 0) {
        cout << "Ошибка: Пробег не может быть отрицательным!" << endl;
        return;
    }
    mileage = m;
}

string Car::getBrand() const { return brand; }
string Car::getColor() const { return color; }
string Car::getBodyType() const { return bodyType; }
double Car::getEngineVolume() const { return engineVolume; }
double Car::getMileage() const { return mileage; }

double Car::calculateFuelConsumption() const {
    if (mileage == 0) return 0;
    return (engineVolume / mileage) * 100;
}

void Car::decreaseMileage(double km) {
    if (km < 0) {
        cout << "Ошибка: Нельзя уменьшить пробег на отрицательное значение!" << endl;
        return;
    }
    if (km > mileage) {
        cout << "Ошибка: Нельзя уменьшить пробег больше текущего значения!" << endl;
        return;
    }
    mileage -= km;
    cout << "Пробег уменьшен на " << km << " км. Новый пробег: " << mileage << " км." << endl;
}

void Car::displayInfo() const {
    cout << "=== Информация об автомобиле ===" << endl;
    cout << "Марка: " << brand << endl;
    cout << "Цвет: " << color << endl;
    cout << "Тип кузова: " << bodyType << endl;
    cout << "Объем двигателя: " << engineVolume << " л" << endl;
    cout << "Пробег: " << mileage << " км" << endl;
    cout << "Средний расход топлива: " << calculateFuelConsumption() << " л/100км" << endl;
    cout << "=================================" << endl;
}