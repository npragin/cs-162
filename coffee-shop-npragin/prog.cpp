#include <iostream>
#include "display.h"

int main() {
	std::cout << "Welcome to the Coffee++ Cafe!" << std::endl;

	if (!file_check()) {
		std::cout << "Either menu.txt or shop_info.txt were not openable. Goodbye." << std::endl;
		return 0;
	}

	shop s;

	int option;
	do {
		option = get_option();
		if (option >= 1 && option <= 6) {
			execute_option(s, option);
		}
	} while (option != 7);

	s.shutdown();

	return 0;
}
