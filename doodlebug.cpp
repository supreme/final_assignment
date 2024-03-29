#include <stdlib.h>
#include "doodlebug.h"
#include "position.h"

namespace Organisms {

  /**
   * Default constructor for a doodlebug.
   */
  Doodlebug::Doodlebug() : Organism() {
    // Deliberately empty
  }

  /**
   * Constructs a doodlebug with a reference to the field containing it.
   * @param field The field containing the doodlebug.
   * @param pos The position of the doodlebug.
   */
  Doodlebug::Doodlebug(Field* field, Position pos) : Organism() {
    this->setField(field);
    this->setPos(pos);
    lastMeal = 0;
  }

/**
 * Handles all of the doodlebug's updating.
 */
void Doodlebug::update() {
    move();
    this->incrementSteps();
    breed();
    starve();
}

/**
 * If there are any ants in the adjacent cells, the doodlebug will move to
 * their cell and eat them. Otherwise, a doodlebug moves just like an ant.
 */
  void Doodlebug::move() {
      Field* f = this->getField(); // Shorter reference
      Position start = this->getPos();
      bool foundAnt = false;
      int i; // Loop counter
      for (i = 0; i < 4; i++) {
          // Implementation of doodlebug 'special' behavior
          Direction dir = static_cast<Direction>(i);
          Position pos = f->simulateMove(start, dir);
          if (f->validPos(pos) && f->getSymbol(pos.x, pos.y) == 'O') {
              lastMeal = 0;
              free(f->getInhabitant(pos));
              f->setInhabitant(pos, NULL);
              this->setPos(pos);
              foundAnt = true;
              break;
          }
      }

      // Perform default organism behavior if no ants in adjacent cells
      if (!foundAnt) { Organism::move(); }
  }

  /**
   * If a doodlebug survives for eight steps, at the end of the step it
   * will spawn a new doodlebug in the same manner as an ant.
   */
  void Doodlebug::breed() {
    if (this->getStepsSurvived() % 8 == 0) {
      Field* field = this->getField();
      Position pos = this->getPos();
      Direction dir = field->getRandomDirection();
      Position spawnPos = field->simulateMove(pos, dir);
      if (field->validPos(spawnPos) && field->isEmpty(spawnPos)) {
        field->setInhabitant(spawnPos, new Doodlebug(field, spawnPos));
      }
    }
  }

  /**
   * Removes the doodlebug from the grid after three steps have passed without
   * the doodlebug eating an ant.
   */
  void Doodlebug::starve() {
    lastMeal += 1;
    if (lastMeal >= 3) {
        this->getField()->setInhabitant(this->getPos(), NULL);
        free(this->getField()->getInhabitant(this->getPos()));
    }
  }

  /**
   * Gets the symbol representation for a Doodlebug.
   * @return The character 'X'
   */
  char Doodlebug::getSymbol() const {
    return 'X';
  }
}
