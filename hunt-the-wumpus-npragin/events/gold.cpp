#include "gold.hpp"

gold::gold(): event("You see something shimmer nearby.\n", 'G') {}

bool gold::encounter(player& p) const {
    p.set_gold(true);

    return true;
}