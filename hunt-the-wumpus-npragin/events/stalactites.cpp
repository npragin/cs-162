#include "stalactites.hpp"
#include <cstdlib>

stalactites::stalactites(): event("You water dripping.\n", 'S') {}

bool stalactites::encounter(player& p) const {
    if (std::rand() % 2) {
        p.die();
    }

    return false;
}