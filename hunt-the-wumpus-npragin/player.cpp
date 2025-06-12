#include "player.hpp"
#include <cstdlib>

player::player(int x, int y): moveable(x, y) {}

bool player::get_gold() const { return gold; }

void player::set_gold(bool gold) { this->gold = gold; }

void player::escape() { escaped = true; }

bool player::get_escaped() { return escaped; }

void player::daze() { dazed = true; }

int player::get_arrows() const { return arrows; }

void player::shoot() { arrows--; }

void player::give_arrow() { arrows++; }

void player::die() { lives--; }

bool player::is_dead() { return !lives; }

void player::move(char direction) {
    if (dazed) {
        int rand = std::rand() % 4;

        if (rand == 0) {
            moveable::move('w');
        } else if (rand == 1) {
            moveable::move('a');
        } else if (rand == 2) {
            moveable::move('s');
        } else {
            moveable::move('d');
        }
        
        dazed = false;
    } else {
        moveable::move(direction);
    }
}

int player::get_lives() { return lives; }

std::pair<bool, int> player::reset_inventory() {
    std::pair<bool, int> p = {gold, arrows};

    gold = false;
    arrows = 0;

    return p;
}