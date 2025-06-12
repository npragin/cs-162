#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "moveable.hpp"
#include <cstdlib>

class player: public moveable {
private:
    bool gold = false;
    bool escaped = false;
    bool dazed = false;
    int arrows = 0;
    int lives = 3;
public:
   /* Name: player (default constructor)
    * Description: Constructs a player
    */
    player() = delete;

   /* Name: player (non-default constructor)
    * Description: Constructs a player with position x, y
    * Parameters:
    *     x (int): x-value
    *     y (int): y-value
    */
    player(int x, int y);

   /* Name: get_gold
    * Description: Returns gold
    * Returns (bool): gold
    */
    bool get_gold() const;

   /* Name: set_gold
    * Description: Sets gold
    * Parameters (bool): New gold value
    */
    void set_gold(bool gold);

   /* Name: escape
    * Description: Sets escape to true
    */
    void escape();

   /* Name: get_escaped
    * Description: Returns true if player has successfully escaped
    * Returns (bool): escaped
    */
    bool get_escaped();

   /* Name: daze
    * Description: Dazes player
    */
    void daze();

   /* Name: get_arrows
    * Description: Returns number of arrows player has
    * Returns (int): arrows
    */
    int get_arrows() const;

   /* Name: shoot
    * Description: Removes an arrow from player
    */
    void shoot();

   /* Name: give_arrow
    * Description: Gives player an arrow
    */
    void give_arrow();

   /* Name: die
    * Description: Removes a life
    */
    void die();

   /* Name: is_dead
    * Description: Returns true if player is perma-dead
    * Returns (bool): true if player has 0 lives after death, else false
    */
    bool is_dead();

   /* Name: move
    * Description: Moves player in direction unless dazed it will be random
    * Parameters (char): Direction to move in, must be w,a,s,d; will default to d
    */
    void move(char direction);

   /* Name: get_lives
    * Description: Returns lives
    * Returns (int): lives
    * */
    int get_lives();

   /* Name: reset_inventory
    * Description: Sets gold and arrows to 0, returns previous values as pair
    * Returns (pair<bool, int>): prev values of [gold, arrows]
    */
    std::pair<bool, int> reset_inventory();
};

#endif