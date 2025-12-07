#pragma once
#include <string>
#include <iostream>
using namespace std;

class Animal {
private:
    string name;
    string species;
    string color;
    int age;
    double weight;

public:
    Animal();
    
    Animal(string n, string s, string c, int a, double w);
    
    void setAnimalData(string n, string s, string c, int a, double w);
    void setName(string n);
    void setSpecies(string s);
    void setColor(string c);
    void setAge(int a);
    void setWeight(double w);
    
    string getName() const;
    string getSpecies() const;
    string getColor() const;
    int getAge() const;
    double getWeight() const;
    
    void increaseWeight(int days);
    void changeName(string newName);
    void displayInfo() const;
};