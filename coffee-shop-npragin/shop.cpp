#include "shop.h"
#include "menu.h"
#include "order.h"
#include <fstream>
#include <string>

shop::shop() {
    populate_from_file();
}

void shop::add_coffee_to_menu(const coffee& c) {
    this->m.add_coffee(c);
}

void shop::add_order(const order& o) {
    order* newOrders = new order[++this->num_orders];

    for (int i = 0; i < this->num_orders - 1; i++) {
        newOrders[i] = this->orders[i];
    }

    newOrders[this->num_orders - 1] = o;

    delete[] this->orders;
    this->orders = newOrders;

    this->add_revenue(this->m.generate_order_cost(o.get_name(), o.get_size(), o.get_quantity()));
}

void shop::populate_from_file() {
    std::ifstream file;
    file.open("shop_info.txt");

    std::getline(file, this->phone);
    std::getline(file, this->address);
}

shop::~shop() {
    if (this->orders != nullptr) {
        delete[] this->orders;
    }
}

shop::shop(const shop& s): phone(s.phone), address(s.address), revenue(s.revenue),
num_orders(s.num_orders) {
    if (this->orders) {
        delete[] this->orders;
    }

    this->orders = new order[this->num_orders];
    for (int i = 0; i < this->num_orders; i++) {
        this->orders[i] = s.orders[i];
    }
}

void shop::operator=(const shop& s) {
    this->phone = s.phone;
    this->address = s.address;
    this->revenue = s.revenue;
    this->num_orders = s.num_orders;

    if (this->orders) {
        delete[] this->orders;
    }

    this->orders = new order[this->num_orders];
    for (int i = 0; i < this->num_orders; i++) {
        this->orders[i] = s.orders[i];
    }
}

std::string shop::to_string() const {
    std::string str;

    str += "Address: " + this->address + '\n';
    str += "Phone: " + this->phone + '\n';
    str += "The shop revenue is: ";
    str += std::to_string(this->revenue);
    str += '\n';

    str += '\n';
    str += "Here is our menu: ";
    str += '\n';
    str += this->m.to_string();
    str += '\n';

    str += "Order Info:";
    str += '\n';
    if (this->orders) {

        for (int i = 0; i < this->num_orders; i++) {
            str += this->orders[i].to_string() + "\n";
        }

    } else {
        str += "(No orders to display)";
        str += '\n';
    }

    return str;
}

std::string shop::get_coffee_names() const {
    std::string str;
    std::string* arr = this->m.get_coffee_names();

    for (int i = 0; i < this->get_num_coffees(); i++) {
        str += std::to_string(i + 1) + ". " + arr[i] + "\n";
    }

    delete[] arr;

    return str;
}

int shop::get_num_coffees() const {
    return this->m.get_num_coffees();
}

void shop::remove_coffee_from_menu(int index) {
    this->m.remove_coffee(index);
}

std::string shop::search_coffee_by_name(std::string query) const {
    return this->m.search_by_name(query);
}

std::string shop::search_coffee_by_budget(double budget) const {
    return this ->m.search_by_budget(budget);
}

std::string shop::menu_to_string() const {
    return this->m.to_string();
}

std::string* shop::get_coffee_names_array() const {
    return this->m.get_coffee_names();
}

int shop::get_next_order_number() const {
    return this->num_orders + 1;
}

void shop::add_revenue(double revenue) { this->revenue += revenue; }

void shop::shutdown() {
	std::ofstream orders;
	orders.open("orders.txt");

    orders << num_orders << "\n";
    for (int i = 0; i < this->num_orders; i++) {
        orders << i + 1 << " " << this->orders[i].get_name() << " "
            << this->orders[i].get_size() << " " << this->orders[i].get_quantity()
            << "\n";
    }

    this->m.shutdown();
}