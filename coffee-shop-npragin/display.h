#ifndef DISPLAY_H
#define DISPLAY_H

#include "shop.h"

/*
 * THIS IS A SUGGESTED FUNCTION. IT IS IMPLEMENTED FOR YOU IN
 *		`display.cpp`
 * Name: get_option
 * Description: Prompt the user for their numbered option selection
 * Returns (int): The number associated with the option selected by the user
 */
int get_option();

/*
 * THIS IS A SUGGESTED FUNCTION. IT IS PARTIALLY IMPLEMENTED FOR YOU IN
 *		`display.cpp`.
 * Name: execute_option
 * Description: Execute the option selected by the user
 * parameters:
 *		s (shop&): A reference to the shop object
 *		option (int): The user's selected option to execute. Must be
 *			between 1 and 7 (inclusive).
 */
void execute_option(shop& s, int option);


/*
* Name: file_check
* Description: Checks if menu.txt and shop-info.txt are readable
* Returns (bool): Whether files are readable or not
*/
bool file_check();

/*
* Name: create_coffee_from_user
* Description: Prompts user for coffee name and price for each size,
*              returns coffee matching specifications
* Returns (coffee): Coffee object w/ name and price matching user input
* Side Effects: Prompts user for coffee name and prices using cin
*/
coffee create_coffee_from_user();

/*
* Name: get_coffee_for_deletion
* Description: Prompts user for number matching coffee index for deletion
* Parameters:
*   shop s: Shop containing coffees for deletion
* Returns (coffee): Coffee object w/ name and price matching user input
* Side Effects: Prompts user for number corresponding to index of coffee
*/
int get_coffee_for_deletion(const shop &s);

/*
* Name: get_coffee_name_query
* Description: Prompts user for coffee name to search by
* Returns (string): Search query to compare against coffee names
* Side Effects: Propmts user for name using cin
*/
std::string get_coffee_name_query();

/*
* Name: get_coffee_budget_query
* Description: Prompts user for coffee budget to search by
* Returns (double): Budget to compare against coffee prices
* Side Effects: Propmts user for budget using cin
*/
double get_coffee_budget_query();

/*
* Name: create_order_from_user
* Description: Prompts user for coffee name, coffee size, and quantity for
*              their order. Returns an order from the specifications
* Parameters:
*   s (const shop&): Shop object containing a menu from which to order
* Returns (order): Order matching specifications WARNING: ORDER_NUMBER INITIALIZED TO 0
* Side Effects: Prompts user using cin
* Post conditions: It is the responsibility of the caller to populate the order_number
                   member
*/
order create_order_from_user(const shop &s);

#endif