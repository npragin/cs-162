#include "order.h"

std::string order::to_string() const {
    std::string str = "";

    str += std::to_string(this->order_number);
    str += " ";
    str += std::to_string(this->quantity);
    str += " ";
    str += this->coffee_size;
    str += " " + this->coffee_name;

    return str;
}

order::order(int order_number, std::string coffee_name, char coffee_size, int quantity) :
order_number(order_number), coffee_name(coffee_name), coffee_size(coffee_size),
quantity(quantity) {}

void order::set_order_number(int order_number) {
    this->order_number = order_number;
}

std::string order::get_name() const { return this->coffee_name; }

char order::get_size() const { return this->coffee_size; }

int order::get_quantity() const { return this->quantity; }