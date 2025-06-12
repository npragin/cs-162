#include "coffee.h"

coffee::coffee(std::string name, double small_cost, double medium_cost, double large_cost) :
name(name), small_cost(small_cost), medium_cost(medium_cost), large_cost(large_cost) {}

std::string coffee::to_string() const {
    std::string str;

    str += this->name + "\n";
    str += "   Small - " + std::to_string(this->small_cost) + "\n";
    str += "   Medium - " + std::to_string(this->medium_cost) + "\n";
    str += "   Large - " + std::to_string(this->large_cost) + "\n";

    return str;
}

std::string coffee::to_string(double budget) const {
    std::string str = "";

    if (small_cost <= budget) {
        str += "   Small - " + std::to_string(this->small_cost) + "\n";
    }
    if (medium_cost <= budget) {
    str += "   Medium - " + std::to_string(this->medium_cost) + "\n";
    }
    if (large_cost <= budget) {
    str += "   Large - " + std::to_string(this->large_cost) + "\n";
    }

    if (str != "") {
        str = this->name + "\n" + str; 
    }

    return str;
}

std::string coffee::get_name() const { return this->name; }

double coffee::get_cost(char size) const {
    if (size == 's') {
        return this->small_cost;
    } else if (size == 'm') {
        return this->medium_cost;
    } else if (size == 'l') {
        return this->large_cost;
    }

    return 0;
}