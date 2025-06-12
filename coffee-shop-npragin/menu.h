#ifndef MENU_H
#define MENU_H

#include "coffee.h"

class menu {
private:
	// Number of coffees in menu
	int num_coffees = 0;

	// Base address of coffee array (nullptr if array is empty)
	coffee* coffees = nullptr;

	/*
	* Name: populate_from_file
	* Description: Populates phone and address fields from menu.txt
	* Side Effects: ifstream to menu.txt is opened and closed
	*/
	void populate_from_file();

public:
	/*
	 * NOTE: THIS IS A REQUIRED FUNCTION. DO NOT ALTER ITS PROTOTYPE.
	 *		YOU MUST IMPLEMENT IT IN `menu.cpp` OR SET IT TO `default`.
	 *		THIS FUNCTION IS USED BY THE BIG 3 TESTING SCRIPT.
	 * Name: menu (default constructor)
	 * Description: Constructs a menu with an empty coffee array
	 */
	menu();

	/*
	 * NOTE: THIS IS A REQUIRED FUNCTION. DO NOT ALTER ITS PROTOTYPE.
	 *		YOU MUST IMPLEMENT IT IN `menu.cpp`. THIS FUNCTION IS USED
	 *		BY THE BIG 3 TESTING SCRIPT.
	 * Name: add_coffee
	 * Description: Adds a coffee to the coffee array
	 * Parameters:
	 *		c (const coffee&): The coffee to add to the array
	 * Post conditions: Coffee added to array (array may need to be
	 *		reallocated, and num_coffees should be incremented by 1)
	 */
	void add_coffee(const coffee& c);

	/*
	* Name: ~menu
	* Description: Destructs a menu that falls out of scope
	*/
	~menu();

	/*
	* Name: menu (copy constructor)
	* Description: Constructs a menu by copying values from existing instance.
	* Parameters:
	*	m (const menu&): Menu to copy values from
	*/
	menu(const menu& m);

	/*
	* Name: = (assignment operator overload)
	* Description: Copies values from existing menu to this menu.
	* Parameters:
	*	m (const shop&): Menu to copy values from
	*/
	void operator=(const menu& m);

	/*
	* Name: to_string
	* Description: Returns string representation of menu object
	* Returns (string): Name and price for each size of all coffees on menu
	*/
	std::string to_string() const;

	/*
	* Name: get_coffee_names
	* Description: Returns dynamic array of strings of coffee names
	* Returns (string*): Dynamic array of all coffee names
	* Post Conditions: Caller is responsible for freeing memory
	*/
	std::string* get_coffee_names() const;

	/*
	* Name: get_num_coffees
	* Description: Returns number of coffees on menu
	* Returns (int): Number of coffees on menu
	*/
	int get_num_coffees() const;

	/*
	* Name: remove_coffee
	* Description: Remove a coffee from the menu's array of coffees
	* Parameters:
	* 	index (int): index of coffee to delete, 1-based
	* Postconditions: Coffee removed from array and resized
	*/
	void remove_coffee(int index);

	/*
	* Name: search_by_name
	* Description: Searches menu for coffee by name against query param and returns
	*			   coffee string representation.
	* Parameters:
	* 	query (string): Coffee name to search against
	* Returns (string): Either matching coffee representation or error statement
	*/
	std::string search_by_name(std::string query) const;

	/*
	* Name: search_by_budget
	* Description: Searches for coffees less than or equal to budget param
	* Parameters:
	* 	budget (double): Maximum price for coffees to be included in result
	* Returns (string): Either matching coffee(s) representation or error statement
	*/
	std::string search_by_budget(double budget) const;

	/*
	* Name: generate_order_cost
	* Description: Given coffee name, size, and quantity returns the cost of the order
	* Parameters:
	*	name (string): Name of coffee ordered
	*	size (char): Size of coffee ordered
	*	quantity (int): number of coffees ordered
	* Returns (double): Total price of the order
	*/
	double generate_order_cost(std::string name, char size, int quantity);

	/*
	* Name: shutdown
	* Description: Saves menu to menu.txt
	* Side Effects: menu.txt opened in truncate mode
	*/
	void shutdown();
};

#endif
