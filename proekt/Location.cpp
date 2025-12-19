#include "Location.h"

Location::Location(string n, string d) : name(n), description(d) {}

void Location::addAction(string action) {
    actions.push_back(action);
}

void Location::addConnection(Location* loc) {
    connections.push_back(loc);
}