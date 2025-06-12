#ifndef STALACTITES_HPP
#define STALACTITES_HPP
#include "event.hpp"

class stalactites : public event {
public:
   /* Name: stalactites (default constructor)
    * Description: Constructs stalactites event
    */
    stalactites();

   /* Name: encounter
    * Description: 50% chance of killing player
	* Parameters:
	*   player (player): Player to be interacted with via encounter
	* Returns (bool): False, indicating it does not need to be deleted by caller
	* Side-effects: Updates player as needed
    */
    bool encounter(player& p) const override;
};

#endif
