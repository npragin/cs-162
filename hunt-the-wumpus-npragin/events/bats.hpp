#ifndef BATS_HPP
#define BATS_HPP
#include "event.hpp"

class bats : public event {
public:
   /* Name: bats (default constructor)
    * Description: Constructs bats event
    */
    bats();

   /* Name: encounter
    * Description: Dazes player
	* Parameters:
	*   player (player): Player to be interacted with via encounter
	* Returns (bool): False, indicating it does not need to be deleted by caller
	* Side-effects: Updates player as needed
    */
    bool encounter(player& p) const override;
};

#endif
