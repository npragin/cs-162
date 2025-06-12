#ifndef EVENT_HPP
#define EVENT_HPP
#include <string>
#include "../player.hpp"

// Event interface
class event {
private:
	std::string percept = "";
	char letter = ' ';
protected:
   /* Name: event (non-default constructor)
    * Description: Constructs an event with the provided percept and char rep.
	* Parameters:
	*	percept (std::string): Percept for the event
	*   letter (char): Representation for the event
    */
	event(std::string percept, char letter);
public:
   /* Name: encounter
    * Description: Does the encounter and interacts with player as needed
	* Parameters:
	*   player (player): Player to be interacted with via encounter
	* Returns (bool): True if must be deleted by caller
	* Side-Effects: Updates player as needed
	* Post-Conditions: Must be deleted by caller
    */
	virtual bool encounter(player& p) const = 0;

   /* Name: get_percept
    * Description: Returns percept
	* Returns (std::string): Percept for the event
    */
	std::string get_percept() const;

   /* Name: get_representation
    * Description: Returns char representation
	* Returns (char): letter
	*/
	char get_representation() const;
};

#endif
