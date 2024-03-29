#ifndef DOODLEBUG_H
#define DOODLEBUG_H

#include <string>
#include "organism.h"
#include "field.h"

using Organisms::Field;

namespace Organisms {

  class Doodlebug : public Organism {
  public:
    Doodlebug();
    Doodlebug(Field* field, Position pos);
    virtual char getSymbol() const;
    virtual void move();
    virtual void breed();
    void starve();
    virtual void update();

  private:
      int lastMeal;
  };
}

#endif
