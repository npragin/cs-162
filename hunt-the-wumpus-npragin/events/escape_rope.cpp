#include "escape_rope.hpp"

escape_rope::escape_rope(): event("", 'E') {}

bool escape_rope::encounter(player& p) const {
    if (p.get_gold()) {
        p.escape();
    }

    return false;
}