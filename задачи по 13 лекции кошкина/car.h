#pragma once
#include <string>
#include <iostream>
using namespace std;

class Car {
private:
    string brand;
    string color;
    string bodyType;
    double engineVolume;
    double mileage;

public:
    Car();
    
    Car(string b, string c, string bt, double ev, double m);
    
    void setCarData(string b, string c, string bt, double ev, double m);
    void setBrand(string b);
    void setColor(string c);
    void setBodyType(string bt);
    void setEngineVolume(double ev);
    void setMileage(double m);
    
    string getBrand() const;
    string getColor() const;
    string getBodyType() const;
    double getEngineVolume() const;
    double getMileage() const;
    
    double calculateFuelConsumption() const;
    void decreaseMileage(double km);
    void displayInfo() const;
};