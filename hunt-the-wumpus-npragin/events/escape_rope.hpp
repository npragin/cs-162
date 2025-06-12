#ifndef ESCAPE_ROPE_HPP
#define ESCAPE_ROPE_HPP
#include "event.hpp"

class escape_rope : public event {
public:
   /* Name: escape_rope (default constructor)
    * Description: Constructs escape_rope event
    */
    escape_rope();

   /* Name: encounter
    * Description: Player escapes if they have gold, else nothing
	* Parameters:
	*   player (player): Player to be interacted with via encounter
	* Returns (bool): False, indicating it does not need to be deleted by caller
	* Side-effects: Updates player as needed
    */
    bool encounter(player& p) const override;
};
#endif
