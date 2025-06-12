#ifndef ORDER_H
#define ORDER_H

#include <string>

class order {
private:
	int order_number = 0;
	std::string coffee_name;
	char coffee_size = 0;
	int quantity = 0;
public:
	/* 
	 * NOTE: THIS IS A REQUIRED FUNCTION. DO NOT ALTER ITS PROTOTYPE.
	 *		YOU MUST IMPLEMENT IT IN `order.cpp` OR SET IT TO `default`.
	 *		THIS FUNCTION IS USED BY THE BIG 3 TESTING SCRIPT.
	 * Name: order (default constructor)
	 * Description: Constructs an order with order_number 0,
	 *		empty coffee name, null (0) coffee size, and 0
	 *		quantity.
	 */
	order() = default;

	/*
	* Name: order (non-default constructor)
	* Description: Constructs an order with specified order_number,
	*			   coffee name, coffee size, and quantity
	*/
	order(int order_number, std::string coffee_name, char coffee_size, int quantity);

	/*
	* Name: to_string
	* Description: Returns string representation of order object
	* Returns (string): Order number, coffee name, size, and quantity
	*/
	std::string to_string() const;

	/*
	* Name: set_order_number
	* Description: Sets order number for this order
	* Parameters:
	*	order_number (int): New order number to be stored
	*/
	void set_order_number(int order_number);

	/*
	* Name: get_name
	* Description: Returns name of coffee ordered
	* Returns (string): name of coffee on order
	*/
	std::string get_name() const;

	/*
	* Name: get_size
	* Description: Returns size of coffee ordered
	* Returns (char): size of coffee on order
	*/
	char get_size() const;

	/*
	* Name: get_quantity
	* Description: Returns number of coffees ordered
	* Returns (int): number of coffees on order
	*/
	int get_quantity() const;
};

#endif
