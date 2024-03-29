#include "ant.h"
#include "position.h"

/**
 * Represents an ant which is a subclass of organism.
 * @author Stephen Andrews
 */
namespace Organisms {

    /**
     * Default constructor for an ant.
     */
    Ant::Ant() : Organism() {
      // Deliberately empty
    }

    /**
     * Constructs an ant with a reference to the field containing it.
     * @param field The field containing the ant.
     * @param pos The position of the ant.
     */
    Ant::Ant(Field* field, Position pos) : Organism() {
      this->setField(field);
      this->setPos(pos);
    }

    /**
     * Handles all of the ant's updating.
     */
    void Ant::update() {
      move();
      this->incrementSteps();
      breed();
    }

    /** Call to parent function */
    void Ant::move() { Organism::move(); }

    /**
     * If an ant survives for three steps, at the end of the step the any will
     * breed. When breeding occurs, a new ant will spawn in an open adjacent
     * cell. If no adjacent cells are open, the ant will not breed.
     */
    void Ant::breed() {
        if (this->getStepsSurvived() % 3 == 0) {
            Field* field = this->getField();
            Position pos = this->getPos();
            Direction dir = field->getRandomDirection();
            Position spawnPos = field->simulateMove(pos, dir);
            if (field->validPos(spawnPos) && field->isEmpty(spawnPos)) {
              field->setInhabitant(spawnPos, new Ant(field, spawnPos));
            }
        }
    }

    /**
     * Gets the symbol representation for an Ant.
     * @return The character 'O'
     */
    char Ant::getSymbol() const {
    	return 'O';
    }
}
