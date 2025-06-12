#include "moveable.hpp"
#include <vector>

moveable::moveable(int x, int y): x(x), y(y) {}

std::vector<int> moveable::get_location() const {
    std::vector coords = {x, y};
    return coords;
}

void moveable::set_location(std::vector<int> coords) {
	x = coords.at(0);
	y = coords.at(1);
}

void moveable::move(char direction) {
    if (direction == 'w') {
		y--;
	} else if (direction == 'a') {
		x--;
	} else if (direction == 's') {
		y++;
	} else {
		x++;
	}
}