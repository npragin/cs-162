#include "menu.h"
#include "coffee.h"
#include <fstream>

menu::menu() {
    populate_from_file();
}

void menu::add_coffee(const coffee& c) {
    coffee* newCoffees = new coffee[++this->num_coffees];

    for (int i = 0; i < this->num_coffees - 1; i++) {
        newCoffees[i] = this->coffees[i];
    }

    newCoffees[this->num_coffees - 1] = c;

    delete[] this->coffees;
    this->coffees = newCoffees;
}

menu::~menu() {
    if (this->coffees != nullptr) {
        delete[] this->coffees;
    }
}

menu::menu(const menu& m): num_coffees(m.num_coffees) {
    if (this->coffees) {
        delete[] this->coffees;
    }

    this->coffees = new coffee[this->num_coffees];
    for (int i = 0; i < this->num_coffees; i++) {
        this->coffees[i] = m.coffees[i];
    }
}

void menu::operator=(const menu& m) {
    this->num_coffees = m.num_coffees;

    if (this->coffees) {
        delete[] this->coffees;
    }

    this->coffees = new coffee[this->num_coffees];
    for (int i = 0; i < this->num_coffees; i++) {
        this->coffees[i] = m.coffees[i];
    }
}

void menu::populate_from_file() {
    std::ifstream file;
    file.open("menu.txt");

    file >> this->num_coffees;
    this->coffees = new coffee[this->num_coffees];

    for (int i = 0; i < this->num_coffees; i++) {
        std::string name;
        double small_cost, medium_cost, large_cost;

        file >> name >> small_cost >> medium_cost >> large_cost;

        this->coffees[i] = coffee(name, small_cost, medium_cost, large_cost);
    }
}

std::string menu::to_string() const {
    if (num_coffees == 0 || !this->coffees) {
        return "(No coffees to display)";
    }

    std::string str;

    for (int i = 0; i < this->num_coffees; i++) {
        str += std::to_string(i + 1) + ". " + this->coffees[i].to_string();
    }
    
    return str;
}

std::string* menu::get_coffee_names() const {
    std::string* arr = new std::string[this->num_coffees];

    for (int i = 0; i < this->num_coffees; i++) {
        arr[i] = this->coffees[i].get_name();
    }

    return arr;
}

int menu::get_num_coffees() const { return this->num_coffees; }

void menu::remove_coffee(int index) {
    coffee* newCoffees = new coffee[--this->num_coffees];

    for (int i = 0; i < index - 1; i++) {
        newCoffees[i] = this->coffees[i];
    }

    for (int i = index; i < this->num_coffees + 1; i++) {
        newCoffees[i - 1] = this->coffees[i];
    }

    delete[] this->coffees;
    this->coffees = newCoffees;
}

std::string menu::search_by_name(std::string query) const {
    for (int i = 0; i < this->num_coffees; i++) {
        if (coffees[i].get_name() == query) {
            return "Results:\n" + coffees[i].to_string();
        }
    }

    return "Sorry, we don't have that product at the moment.\n";
}

std::string menu::search_by_budget(double budget) const {
    std::string result = "";

    for (int i = 0; i < this->num_coffees; i++) {
        result += coffees[i].to_string(budget);
    }
    
    if (result == "") {
        return "Sorry, we don't have a product less than or equal to your budget.\n";
    }

    return result;
}

double menu::generate_order_cost(std::string name, char size, int quantity) {
    for (int i = 0; i < this->num_coffees; i++) {
        if (this->coffees[i].get_name() == name) {
            return this->coffees[i].get_cost(size) * quantity;
        }
    }

    return 0;
}

void menu::shutdown() {
    std::ofstream menu;
    menu.open("menu.txt");

    menu << num_coffees << "\n";
    for (int i = 0; i < this->num_coffees; i++) {
        menu << this->coffees[i].get_name() << " " << this->coffees[i].get_cost('s')
            << " " << this->coffees[i].get_cost('m') << " "
            << this->coffees[i].get_cost('l') << "\n";
    }
}