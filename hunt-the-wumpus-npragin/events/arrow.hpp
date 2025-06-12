#ifndef ARROW_HPP
#define ARROW_HPP
#include "event.hpp"

class arrow : public event { 
public:
   /* Name: arrow (default constructor)
    * Description: Constructs an arrow
    */
    arrow();

   /* Name: encounter
    * Description: Adds an arrow to player
	* Parameters:
	*   player (player): Player to be interacted with via encounter
	* Returns (bool): True, indicating it must be deleted by caller
	* Side-effects: Updates player as needed
    * Post-conditions: Must be deleted by caller
    */
    bool encounter(player& p) const override;
};

#endif
