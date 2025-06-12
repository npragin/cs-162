#include "arrow.hpp"

arrow::arrow(): event("You see an arrow on the ground in an adjacent room.\n", 'A') {}

bool arrow::encounter(player& p) const {
    p.give_arrow();

    return true;
}