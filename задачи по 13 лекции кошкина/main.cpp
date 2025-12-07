#include <iostream>
#include "car.h"
#include "animal.h"
using namespace std;

int main() {
    cout << "=== ТЕСТИРОВАНИЕ КЛАССА CAR ===" << endl;
    
    cout << "\n1. Статический объект Car:" << endl;
    Car car1("Toyota", "Красный", "Седан", 2.0, 15000);
    car1.displayInfo();
    cout << "Расход топлива: " << car1.calculateFuelConsumption() << " л/100км" << endl;
    car1.decreaseMileage(500);
    car1.displayInfo();
    
    cout << "\n2. Динамический объект Car:" << endl;
    Car* car2 = new Car("BMW", "Черный", "Внедорожник", 3.0, 80000);
    car2->displayInfo();
    cout << "Расход топлива: " << car2->calculateFuelConsumption() << " л/100км" << endl;
    car2->decreaseMileage(1000);
    car2->displayInfo();
    
    cout << "\n3. Массив объектов Car:" << endl;
    Car cars[3];
    cars[0].setCarData("Lada", "Белый", "Хэтчбек", 1.6, 50000);
    cars[1].setCarData("Kia", "Синий", "Седан", 1.8, 30000);
    cars[2].setCarData("Hyundai", "Зеленый", "Кроссовер", 2.4, 20000);
    
    for (int i = 0; i < 3; i++) {
        cout << "Автомобиль " << i + 1 << ":" << endl;
        cars[i].displayInfo();
        cout << "Расход: " << cars[i].calculateFuelConsumption() << " л/100км" << endl;
        cout << "------------------------" << endl;
    }
    
    cout << "\n=== ТЕСТИРОВАНИЕ КЛАССА ANIMAL ===" << endl;
    
    cout << "\n1. Статический объект Animal:" << endl;
    Animal animal1("Барсик", "Кот", "Рыжий", 3, 4.5);
    animal1.displayInfo();
    animal1.increaseWeight(7);
    animal1.changeName("Мурзик");
    animal1.displayInfo();
    
    cout << "\n2. Динамический объект Animal:" << endl;
    Animal* animal2 = new Animal("Шарик", "Собака", "Белый", 5, 12.3);
    animal2->displayInfo();
    animal2->increaseWeight(10);
    animal2->changeName("Бобик");
    animal2->displayInfo();
    
    cout << "\n3. Массив объектов Animal:" << endl;
    Animal animals[3];
    animals[0].setAnimalData("Рекс", "Собака", "Коричневый", 4, 8.2);
    animals[1].setAnimalData("Мурка", "Кот", "Серый", 2, 3.1);
    animals[2].setAnimalData("Кеша", "Попугай", "Зеленый", 1, 0.15);
    
    for (int i = 0; i < 3; i++) {
        cout << "Животное " << i + 1 << ":" << endl;
        animals[i].displayInfo();
        animals[i].increaseWeight(5);
        cout << "------------------------" << endl;
    }
    
    cout << "\n4. Тестирование обработки ошибок:" << endl;
    cout << "Тестирование неверных данных автомобиля:" << endl;
    Car invalidCar;
    invalidCar.setBrand("");
    invalidCar.setEngineVolume(-2.0);
    invalidCar.setMileage(-100);
    invalidCar.decreaseMileage(-50);
    
    cout << "\nТестирование неверных данных животного:" << endl;
    Animal invalidAnimal;
    invalidAnimal.setName("");
    invalidAnimal.setAge(-1);
    invalidAnimal.setWeight(-5.0);
    invalidAnimal.increaseWeight(-3);
    
    delete car2;
    delete animal2;
    
    return 0;
}