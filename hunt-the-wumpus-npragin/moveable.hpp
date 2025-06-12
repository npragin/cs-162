#ifndef MOVEABLE_HPP
#define MOVEABLE_HPP

#include <vector>

class moveable {
private:
    int x;
    int y;
protected:
    /* Name: Moveable (non-default constructor)
    * Description: Initializes Moveable values x and y with provided args
    * Parameters:
    *     x (int): x-value
    *     y (int): y-value
    */
    moveable(int x, int y);
public:
    moveable() = delete;


   /* Name: get_location
    * Description: Returns vector<int> representing x and y.
    * Returns (vector<int>): [x, y]
    */
   std::vector<int> get_location() const;

   /* Name: set_location
    * Description: Takes vector<int> representing x and y and sets values.
    * Parameters (vector<int>): [x, y]
    */
   void set_location(std::vector<int> coords);

   /* Name: move
    * Description: Entity takes 1 turn worth of moves in provided direction
    * Parameters:
    *     direction (char): Direction in which to move w,a,s,d; will default to d
    * Preconditions: Ensure char is w,a,s, or d; will default to d
    */
    virtual void move(char direction);
};

#endif