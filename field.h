/**
 * This is the header file field.h.
 * This is the interface for the class Field.
 * Note that the field coordinates are x, which increases to the right,
 * and y, which increases down (Like on Web pages).
 */
#ifndef FIELD_H
#define FIELD_H

#include <string>
#include "organism.h"
#include "position.h"

using std::string;

namespace Organisms {

  class Field {
  public:
    Field( );
    Field(int width, int height);
    class Organism* getInhabitant(Position pos);
    int setInhabitant(Position pos, Organism *org);
    char getSymbol(int x, int y);
    int print();
    bool isEmpty(Position pos);
    bool validPos(Position pos);
    Direction getRandomDirection();
    void step(char symbol);
    Position simulateMove(Position start, Direction dir);

  private:
    int width; // How many columns wide the field is.
    int height; // How many rows tall the field is.

    /* We store the field as 2-D array of pointers to Organisms.
     * It is actually implemented as a 1-D array of pointers.
     * Each entry is a pointer to an array of pointers to Organisms
     * (each of these arrays represents one column)..
     * Each entry of THOSE arrays is a pointer to an Organism.
     * (NULL means uninhabited).
     * This way we can access the array as array[row][column].
     */

    Organism*** array;
  };

} //Organisms

#endif //FIELD_H
