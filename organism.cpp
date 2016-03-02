/** This is the file: organism.cpp
 * This is the implementation for the class Organism.
 * The interface for the class Organism is in the header file employee.h.
 */
#include <string>
#include <cstdlib>
#include <iostream>
#include "organism.h"
#include "position.h"
#include "field.h"
using std::string;
using std::cout;
using std::endl;

namespace Organisms {
  /**
   * The default constructor for the Organism class.
   */
  Organism::Organism() : stepsSurvived(0), pos(Position(0, 0)),
    updated(false) {
      // Deliberately empty
  }

  /**
   * Gets the amount of steps the organism survived.
   * @return The amount of steps survived.
   */
   int Organism::getStepsSurvived() {
     return stepsSurvived;
   }

   /**
    * Updates the steps survived by one (+1).
    */
   void Organism::incrementSteps() {
       stepsSurvived += 1;
   }

   /**
    * Gets the field the organism belongs to.
    * @return The field the organism belongs to.
    */
   Field* Organism::getField() {
       return field;
   }

   /**
    * Sets the field the organism belongs to.
    * @return The field to set.
    */
   void Organism::setField(Field* field) {
       this->field = field;
   }

   /**
    * Sets the position of the organism.
    * @param  pos The position to set.
    */
   void Organism::setPos(Position pos) {
       Position old = this->pos;
       this->pos = pos;
       field->setInhabitant(old, NULL);
       field->setInhabitant(pos, this);
   }

   /**
    * Gets the position of the organism.
    * @return The position.
    */
   Position Organism::getPos() {
     return this->pos;
   }

  /** Returns the one-character symbol for this organism
   * @return A single character for dislaying this organism.
   */
  char Organism::getSymbol() const {
    return '_';
  }

  /**
   * Sets the updated flag.
   * @param flag The value to set.
   */
  void Organism::setUpdated(bool flag) {
    updated = flag;
  }

  /**
   * Gets the updated flag.
   * @return The updated flag.
   */
  bool Organism::hasUpdated() {
    return updated;
  }
} // Organisms
