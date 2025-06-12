#ifndef COFFEE_H
#define COFFEE_H

#include <string>

class coffee {
private:
	std::string name;
	double small_cost = 0.0;
	double medium_cost = 0.0;
	double large_cost = 0.0;

public:
	/*
	 * NOTE: THIS IS A REQUIRED FUNCTION. DO NOT ALTER ITS PROTOTYPE.
	 *		YOU MUST IMPLEMENT IT IN `coffee.cpp` OR SET IT TO `default`.
	 *		THIS FUNCTION IS USED BY THE BIG 3 TESTING SCRIPT.
	 * Name: coffee (default constructor)
	 * Description: Constructs a coffee object with an empty name
	 *		and all costs of 0
	 */
	coffee() = default;

	/*
	* Name: coffee (non-default constructor)
	* Description: Constructs a coffee object from parameters
	* Parameters:
	*		name (string): Name of coffee
	*		small_cost (double): Price of small coffee
	*		medium_cost (double): Price of medium coffee
	*		large_cost (double): Price of large coffee
	*/
	coffee(std::string name, double small_cost, double medium_cost, double large_cost);

	/*
	* Name: to_string
	* Description: Returns string representation of coffee object
	* Returns (string): Name and price for each size of coffee
	*/
	std::string to_string() const;

	/*
	* Name: to_string
	* Description: Returns string representation of coffee object, only including coffee
	*			   with price less than or equal to the budget param
	* Parameters:
	*	budget (double): Maximum price for coffees to be included
	* Returns (string): Name and price for each size of coffee matching budget constraint
	*/
	std::string to_string(double budget) const;

	/*
	* Name: get_name
	* Description: Returns name of coffee object
	* Returns (string): Name of coffee
	*/
	std::string get_name() const;

	/*
	* Name: get_cost
	* Description: Returns cost of specified size
	* Parameters:
	*	size (char): Must be s/m/l, represents which cost to return
	* Returns (double): Price of specified size of coffee
	*/
	double get_cost(char size) const;
};

#endif
