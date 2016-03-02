/**
 * This is the header file organism.h.
 * This is the interface for the class Organism
 * This is primarily intended to be used as a base class to derive
 * classes for different kinds of organisms.
 */
#ifndef ORGANISM_H
#define ORGANISM_H

#include "position.h"

namespace Organisms {

  class Organism {
  public:
    Organism();
    int getStepsSurvived();
    virtual char getSymbol() const;
    virtual void move() = 0;
    virtual void breed() = 0;
    void setPos(Position pos);
    class Field* getField();
    void setField(Field* field);
    Position getPos();
    virtual void update() = 0;
    void incrementSteps();
    void setUpdated(bool flag);
    bool hasUpdated();

  private:
    int stepsSurvived;
    Position pos;
    class Field* field;
    bool updated;
  };

} //Organisms

#endif //ORGANISM_H
