#include "bats.hpp"

bats::bats(): event("You hear wings flapping.\n", 'B') {}

bool bats::encounter(player& p) const {
    p.daze();

    return false;
}