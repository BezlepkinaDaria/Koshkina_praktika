#pragma once
#include <string>
#include <vector>
using namespace std;

class Location {
public:
    string name;
    string description;
    vector<string> actions;
    vector<Location*> connections;

    Location(string n, string d);
    void addAction(string action);
    void addConnection(Location* loc);
};