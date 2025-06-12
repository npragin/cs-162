#ifndef ROOM_HPP
#define ROOM_HPP

#include "./events/event.hpp"

// Room interface
class room {
private: 
	event* e = nullptr;
public:
   /*
	* Name: room (default constructor)
	* Description: Constructs a room without an event
	*/
	room() = default;

   /*
	* Name: room (non-default constructor)
	* Description: Constructs a room with a provided event
	* Parameters (event): event to be in the room
	*/
	room(event* e);

   /*
	* Name: ~room
	* Description: Destructs a room that falls out of scope
	*/
	~room();

   /*
	* Name: room (copy constructor)
	* Description: Constructs a room by copying values from existing instance.
	* Parameters:
	*	r (const room&): room to copy values from
	*/
	room(const room& r);

   /*
	* Name: = (assignment operator overload)
	* Description: Copies values from existing room to this room.
	* Parameters:
	*	r (const room&): room to copy values from
	*/
	void operator=(const room& r);

   /* Name: set_event
    * Description: Sets event to parameter
	* Parameters (event* e): Event to store in room
	* Side-effects: Deletes existing event if exists
    */
	void set_event(event* e);

	/* Name: set_event
    * Description: Sets event to parameter
	* Parameters (event* e, bool b): Event to store in room, bool if need delete
	* Side-effects: Deletes existing event if exists and bool true
    */
	void set_event(event* e, bool b);

   /*
	* Name: get_event_char
	* Description: Returns char representation of event
	* Returns (char): Representation of event
	*/
	char get_event_char() const;

   /* Name: get_event_percept
    * Description: Returns percept for contained event
	* Returns (std::string): Percept for the event
    */
	std::string get_event_percept() const;

   /* Name: encounter_event
    * Description: Does the encounter and interacts with player as needed
	* Parameters:
	*   player (player): Player to be interacted with via encounter
	* Returns (bool): True if must be deleted by caller
	* Side-effects: Updates player as needed, deletes event if necessary
    */
	void encounter_event(player& p);

   /* Name: contains_event
    * Description: Returns true if room contains an event, false otherwise
	* Returns (bool): True if room contains an event, false otherwise
	*/
	bool contains_event() const;
};

#endif
