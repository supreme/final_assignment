#ifndef ANT_H
#define ANT_H

#include <string>
#include "organism.h"
#include "field.h"

using Organisms::Field;

namespace Organisms {

  class Ant : public Organism {
  public:
    Ant();
    Ant(Field* field, Position pos);
    virtual char getSymbol() const;
    virtual void move();
    virtual void breed();
    virtual void update();
  };
}

#endif
