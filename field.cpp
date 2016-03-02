/** This is the file: field.cpp
 * This is the implementation for the class Field.
 * The interface for the class Field is in the header file employee.h.
 */
#include <string>
#include <cstdlib>
#include <iostream>
#include "field.h"
#include "organism.h"

using std::string;
using std::cout;
using std::endl;

namespace Organisms {

/** The default constructor for the Field class.
 *  Initializes size to 0 by 0.
 */
Field::Field( ) {
	this->height = 0;
	this->width = 0;
	this->array = (Organism***) NULL;
}

/** Constructor for the Field class
 * @param width Number of columns in the field
 *    (coordinate increases to the right)
 * @param height Number of rows tall (coordinate increases as you
 *    move down the page).
 *
 */
Field::Field(int width, int height) {
	this->width = width; // Remember width and height of the field.
	this->height = height; // Use "this" to specify field instead of param.

	// Now allocate the 2-D array which forms the filed.
	int x; // Column and row coordinates.

	// First, allocate the array of pointers to the columns
	array = (Organism***) (calloc(width, sizeof(Organism**)));
	for (x = 0; x < width; x++) {
		// Allocate each column array.
		array[x] = (Organism**) (calloc(height, sizeof(Organism*)));
	}
	// We want all the pointers in the column array to be NULL.
	// We do not need to initialize them, because calloc() fills with zeroes.
}

/**
 * Handles the main logic of updating organsims.
 */
void Field::step(char symbol) {
	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			Organism* o = getInhabitant(Position(x, y));
			if (o != NULL && !o->hasUpdated()) {
				o->update();
				o->setUpdated(true);
			}
		}
	}
}

/** Retrieves the Organism from a specified spot on the field.
 * @param pos The position to check.
 * @return Pointer to the object. NULL if empty.
 */
Organism* Field::getInhabitant(Position pos) {
	return array[pos.x][pos.y];
}

/** Stores an Organism into a specified spot on the field.
 * @param pos The position to set.
 * @param org Pointer to the Organism object.
 * @return Just 0 for now.
 */
int Field::setInhabitant(Position pos, Organism *org) {
	array[pos.x][pos.y] = org;
	return 0;
}

/* Get a printable representation of what is in a cell
 * in a particular place on the field.
 * @param x X-coordinate (horizontal)
 * @param y Y-coordinate (vertical)
 * @return Symbol of Organism at that location
 *   Blank if uninhabited.
 *   '?' if invalid cell coordinates.
 */
char Field::getSymbol(int x, int y) {
	if ((array == NULL) || (x >= width) || (y >= height)) {
		return '?';
	}

	Organism* org = array[x][y];
	if (org == NULL) {
		return ' ';
	} else {
		return org->getSymbol();
	}
}

/** Prints the field to standard output
 * @return Just a 0 for now
 */
int Field::print() {
	int x, y; // Coordinates
	printf("\n-----------------------\n");
	for (y = 0; y < height; y++) { // Print one complete row
		for(x = 0; x < width; x++) { // Print each cell
			Organism* o = getInhabitant(Position(x, y));
			if (o != NULL) {
				// Reset the updated flag so the organism can be updated
				// again on the next step
				o->setUpdated(false);
			}
			printf("%c", getSymbol(x, y));
		}
		printf("\n"); // End of line
	}
	printf("-----------------------\n");

	return 0;
}

/**
 * Determines whether or not a position on the grid is empty.
 * @param pos The position to check.
 * @return true if so, false if not
 */
bool Field::isEmpty(Position pos) {
	return getInhabitant(pos) == NULL;
}

/**
 * Gets a random direction from the direction enum.
 * @return A random direction.
 */
Direction Field::getRandomDirection() {
	return Direction(rand() % 4);
}

/**
 * Determines whether or not a location is a valid position in the field.
 * @param  x The x position.
 * @param  y The y position.
 * @return   true if so, false if not
 */
bool Field::validPos(Position pos) {
	if (pos.x < 0 || pos.y < 0) { return false; }
	if (pos.x >= width || pos.y >= height) { return false; }

	return true;
}

/**
 * Simulates a move in a certain direction and returns the resulting position.
 * @param  start The starting position.
 * @param  dir   The desired direction to move in.
 * @return       The position after moving in the specified path.
 */
Position Field::simulateMove(Position start, Direction dir) {
	int x = start.x;
	int y = start.y;
	switch (dir) {
	case NORTH:
		return Position(x, y + 1);
		break;
	case SOUTH:
		return Position(x, y - 1);
		break;
	case EAST:
		return Position(x + 1, y);
		break;
	case WEST:
		return Position(x - 1, y);
		break;
	}
}


} // Organisms
