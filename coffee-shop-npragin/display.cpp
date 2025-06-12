#include <iostream>
#include <fstream>
#include "display.h"
#include "coffee.h"

/*
 * THIS IS A SUGGESTED FUNCTION.
 * Name: print_options()
 * Description: Print options to the user
 */
void print_options() {
	std::cout << std::endl << "What would you like to do?" << std::endl;
	std::cout << "	1. View shop info" << std::endl;
	std::cout << "	2. Add an item to menu" << std::endl;
	std::cout << "	3. Remove an item from menu" << std::endl;
	std::cout << "	4. Search by coffee name" << std::endl;
	std::cout << "	5. Search by price" << std::endl;
	std::cout << "	6. Place an order" << std::endl;
	std::cout << "	7. Log out" << std::endl;
}

/*
 * THIS IS A SUGGESTED FUNCTION.
 * Name: print_selection_error
 * Description: Scolds the user for selecting a bad option
 *		number
 */
void print_selection_error() {
	std::cout << "Error: You must choose one of the 7 options provided"
		<< std::endl;
}

int get_option() {
	int option;
	bool first = true;
	do {
		if (!first) {
			print_selection_error();
		}
		first = false;
		print_options();
		std::cout << "Selection: ";
		std::cin >> option;
	} while (option < 1 || option > 7);

	std::cout << std::endl;

	return option;
}

void execute_option(shop& s, int option) {
	if (option == 1) {
		std::cout << s.to_string() << std::endl;
	} else if (option == 2) {
		s.add_coffee_to_menu(create_coffee_from_user());

		std::cout << "This new drink has been successfully added to the menu!"
            << std::endl << std::endl;
	} else if (option == 3) {
		s.remove_coffee_from_menu(get_coffee_for_deletion(s));

		std::cout << std::endl
			<< "This drink has been successfully removed from the menu!" << std::endl
			<< std::endl;
	} else if (option == 4) {
		std::cout << s.search_coffee_by_name(get_coffee_name_query()) << std::endl;
	} else if (option == 5) {
		std::cout << s.search_coffee_by_budget(get_coffee_budget_query()) << std::endl;
	} else if (option == 6) {
		order o = create_order_from_user(s);

		o.set_order_number(s.get_next_order_number());
		
		s.add_order(o);

		std::cout << std::endl << "Your order has been placed successfully." << std::endl;
	}
}

bool file_check() {
	std::ifstream shopFile, menuFile;
    shopFile.open("shop_info.txt");
	menuFile.open("menu.txt");

	if (shopFile.is_open() && menuFile.is_open()) {
		return true;
	}

	return false;
}

coffee create_coffee_from_user() {
	std::string name;
	double s, m, l;
	s = -1;
	m = -1;
	l = -1;

	std::cout << "Enter the name of the new coffee drink (in 1 word): ";
	std::cin >> name;

	while (s < 0) {
		std::cout << "Enter price of small size (8oz): ";
		std::cin >> s;
	}

	while (m < 0) {
		std::cout << "Enter price of medium size (12oz): ";
		std::cin >> m;
	}

	while (l < 0) {
		std::cout << "Enter price of large size (16oz): ";
		std::cin >> l;
	}

	std::cout << std::endl;

	return coffee(name, s, m, l);
}

int get_coffee_for_deletion(const shop &s) {
	int choice = 0;

	std::cout << s.get_coffee_names();

	while (choice < 1 || choice > s.get_num_coffees()) {
		std::cout << "Which of the drinks above from our menu would you like to remove? "
			"Enter 1-" << s.get_num_coffees() << ": ";

		std::cin >> choice;
	}

	return choice;
}

std::string get_coffee_name_query() {
	std::string query;

	std::cout << "Enter the coffee name: ";
	std::cin >> query;
	std::cout << std::endl;

	return query;
}

double get_coffee_budget_query() {
	double budget;
	
	std::cout << "Enter your budget for one drink, "
		<< "and I will list out our products that cheaper or equal to your budget: ";
	std::cin >> budget;
	std::cout << std::endl;

	return budget;
}

order create_order_from_user(const shop &s) {
	char coffee_size = 'x';
	int quantity = 0;
	int coffeeSelection = 0;

	std::cout << s.menu_to_string() << std::endl;

	while(coffeeSelection < 1 || coffeeSelection > s.get_num_coffees()) {
		std::cout << "Which of the drinks above from our menu would you like to order? "
			<< "Enter 1-" << s.get_num_coffees() << ": ";
		std::cin >> coffeeSelection;
	}

	std::cout << std::endl;

	while (coffee_size != 's' && coffee_size != 'm' && coffee_size != 'l') {
		std::cout << "Enter the size: s-small, m-medium, l-large: ";
		std::cin >> coffee_size;
	}

	std::cout << std::endl;

	while (quantity < 1) {
		std::cout << "Enter quantity: ";
		std::cin >> quantity;
	}

	std::string* arr = s.get_coffee_names_array();

	order o = order(0,
			arr[coffeeSelection - 1],
			coffee_size,
			quantity);

	delete[] arr;
		
	return o;
}