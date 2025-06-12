#include "event.hpp"
#include <string>

event::event(std::string percept, char letter): percept(percept), letter(letter) {}

std::string event::get_percept() const {
    return percept;
}

char event::get_representation() const {
    return letter;
}