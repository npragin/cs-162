#ifndef SHOP_H
#define SHOP_H

#include <string>

#include "menu.h"
#include "order.h"

class shop {
private:
	menu m;

	std::string phone;
	std::string address;
	double revenue = 0;

	// Number of orders
	int num_orders = 0;

	// Base address of order array (nullptr if array is empty)
	order* orders = nullptr;

	/*
	* Name: populate_from_file
	* Description: Populates phone and address fields from shop-info.txt
	* Side Effects: ifstream to shop-info.txt is opened and closed
	*/
	void populate_from_file();

public:
	/*
	 * NOTE: THIS IS A REQUIRED FUNCTION. DO NOT ALTER ITS PROTOTYPE.
	 *		YOU MUST IMPLEMENT IT IN `shop.cpp` OR SET IT TO `default`.
	 *		THIS FUNCTION IS USED BY THE BIG 3 TESTING SCRIPT.
	 * Name: shop (default constructor)
	 * Description: Constructs a shop with a defaultly-constructed menu,
	 *		an empty phone number and address, 0 revenue, and no orders.
	 */
	shop();

	/*
	 * NOTE: THIS IS A REQUIRED FUNCTION. DO NOT ALTER ITS PROTOTYPE.
	 *		YOU MUST IMPLEMENT IT IN `shop.cpp`. THIS FUNCTION IS USED
	 *		BY THE BIG 3 TESTING SCRIPT.
	 * Name: add_coffee_to_menu
	 * Description: Adds a coffee to the shop's menu
	 * Parameters:
	 *		c (const coffee&): The coffee to add to the shop's menu
	 * Post conditions: Coffee added to menu
	 */
	void add_coffee_to_menu(const coffee& c);

	/*
	 * NOTE: THIS IS A REQUIRED FUNCTION. DO NOT ALTER ITS PROTOTYPE.
	 *		YOU MUST IMPLEMENT IT IN `shop.cpp`. THIS FUNCTION IS USED
	 *		BY THE BIG 3 TESTING SCRIPT.
	 * Name: add_order
	 * Description: Adds an order to the order array
	 * Parameters:
	 *		o (const order&): The order to add to the array
	 * Post conditions: Order added to array (array may need to be
	 *		reallocated, and num_orders should be incremented by 1)
	 */
	void add_order(const order& o);

	/*
	* Name: ~shop
	* Description: Destructs a shop that falls out of scope
	*/
	~shop();

	/*
	* Name: shop (copy constructor)
	* Description: Constructs a shop by copying values from existing instance.
	* Parameters:
	*	s (const shop&): Shop to copy values from
	*/
	shop(const shop& s);

	/*
	* Name: = (assignment operator overload)
	* Description: Copies values from existing shop to this shop.
	* Parameters:
	*	s (const shop&): Shop to copy values from
	*/
	void operator=(const shop& s);

	/*
	* Name: to_string
	* Description: Returns string representation of shop object
	* Returns (string): Address, phone number, menu and orders of this shop
	*/
	std::string to_string() const;

	/*
	* Name: get_coffee_names
	* Description: Returns string representing numbered list of coffee names
	* Returns (string): Numbered list of all coffee names
	*/
	std::string get_coffee_names() const;

	/*
	* Name: get_num_coffees
	* Description: Returns number of coffees on menu
	* Returns (int): Number of coffees on menu
	*/
	int get_num_coffees() const;

	/*
	* Name: remove_coffee_from_menu
	* Description: Remove a coffee from the shop's menu
	* Parameters:
	* 	index (int): index of coffee to delete, 1-based
	* Postconditions: Coffee removed from menu
	*/
	void remove_coffee_from_menu(int index);

	/*
	* Name: search_coffee_by_name
	* Description: Searches menu for coffee by name against query param and returns
	*			   coffee string representation.
	* Parameters:
	* 	query (string): Coffee name to search against
	* Returns (string): Either matching coffee representation or error statement
	*/
	std::string search_coffee_by_name(std::string query) const;

	/*
	* Name: search_coffee_by_budget
	* Description: Searches menu for coffees less than or equal to budget param
	* Parameters:
	* 	budget (double): Maximum price for coffees to be included in result
	* Returns (string): Either matching coffee(s) representation or error statement
	*/
	std::string search_coffee_by_budget(double budget) const;

	/*
	* Name: to_string
	* Description: Returns string representation of shop's menu object
	* Returns (string): Numbered list of coffees on menu with prices for each size
	*/
	std::string menu_to_string() const;

	/*
	* Name: get_coffee_names
	* Description: Returns dynamic string array of coffee names on menu
	* Returns (string*): Dynamic array of coffee names on menu of shop
	* Post Conditions: Caller is responsible for freeing memory
	*/
	std::string* get_coffee_names_array() const;

	/*
	* Name: get_next_order_number
	* Description: Returns the order number of the next order if added
	* Returns (int): Next order number expected
	*/
	int get_next_order_number() const;

	/*
	* Name: add_revenue
	* Description: Adds parameter to total revenue of shop
	* Parameters:
	*	revenue (double): number to be added to shop's revenue total
	*/
	void add_revenue(double revenue);

	/*
	* Name: shutdown
	* Description: Saves orders to orders.txt and calls menu's shutdown function
	* Side Effects: orders.txt opened in truncate mode
	*/
	void shutdown();
};

#endif
