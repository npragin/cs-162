#ifndef GOLD_HPP
#define GOLD_HPP
#include "event.hpp"

class gold : public event {
public:
   /* Name: gold (default constructor)
    * Description: Constructs a gold
    */
    gold();

   /* Name: encounter
    * Description: Gives player gold
	* Parameters:
	*   player (player): Player to be interacted with via encounter
	* Returns (bool): True, indicating it must be deleted by caller
	* Side-effects: Updates player as needed
    * Post-conditions: Must be deleted by caller
    */
    bool encounter(player& p) const override;
};

#endif
