#ifndef WUMPUS_HPP
#define WUMPUS_HPP
#include "event.hpp"
#include "../moveable.hpp"
#include <vector>

class wumpus : public event, public moveable {
private:
    bool dead = false;
public:
    wumpus() = delete;

   /* Name: wumpus (non-default constructor)
    * Description: Constructs a wumpus with position x, y
    * Parameters:
    *     x (int): x-value
    *     y (int): y-value
    */
    wumpus(int x, int y);

   /* Name: encounter
    * Description: Kills player
	* Parameters:
	*   player (player): Player to be interacted with via encounter
	* Returns (bool): False, indicating it does not need to be deleted by caller
	* Side-effects: Updates player as needed
    */
    bool encounter(player& p) const override;

   /* Name: move
    * Description: Randomly moves in one of the possible directions
    * Parameters (vector<char>): Representing moveable directions, must be a,w,s,d
    * Pre-conditions: Ensure parameter is a,w,s,d, will default as d
    */
    void move(std::vector<char> directions);
    
   /* Name: is_dead
    * Description: Returns true if wumpus is dead
    * Returns (bool): dead
    */
    bool is_dead();

   /* Name: kill
    * Description: Kills wumpus, sets dead to true
    */
    void kill();
};


#endif
