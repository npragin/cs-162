#include "wumpus.hpp"
#include <cstdlib>

wumpus::wumpus(int x, int y): moveable(x, y), event("You smell a horrible stench.\n", 'W') {}

bool wumpus::encounter(player& p) const {
    if (!dead) {
        p.die();
    }
    
    return false;
}

void wumpus::move(std::vector<char> directions) {
    if (directions.size() == 0) {
        return;
    }

    int rand = std::rand() % directions.size();

    moveable::move(directions.at(rand));
}

bool wumpus::is_dead() { return dead; }

void wumpus::kill() { dead = true; }