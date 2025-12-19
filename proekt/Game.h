#pragma once
#include "Player.h"
#include "Location.h"
#include <vector>
#include <string>
using namespace std;

class Game {
private:
    Player player;
    Location* currentLocation;
    vector<Location*> allLocations;
    bool gameEnd;
    string ending;

    void showMovementOptions(vector<Location*> connections); 

public:
    Game();
    ~Game();

    void createGame();
    void handleChoice(int choice); 
    void showEnd();
    void run();
};