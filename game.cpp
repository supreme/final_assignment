#include <iostream>
#include "field.h"
#include "organism.h"
#include "ant.h"
#include "doodlebug.h"

using std::cout;
using std::endl;
using std::cin;
using Organisms::Organism;
using Organisms::Field;
using Organisms::Ant;
using Organisms::Doodlebug;

// Smaller during testing
#define FIELD_WIDTH (20)
#define FIELD_HEIGHT (20)

#define ANT_POPULATION (100)
#define DOODLEBUG_POPULATION (5)

Position getRandomPos() {
  int x  = (rand() % 20);
  int y = (rand() % 20);
  return Position(x, y);
}

int main( ) {
  Field* field; // Holds a pointer to the playing field object
  srand(time(NULL));
  printf("Playing the ants vs. doodlebugs game.\n");

  field = new Field(FIELD_WIDTH, FIELD_HEIGHT);

  int i; // Loop counter
  for (i = 0; i < ANT_POPULATION; i++) {
    Position pos = getRandomPos();
    while (!field->isEmpty(pos)) {
      pos = getRandomPos();
    }

    Organism* ant = new Ant(field, pos);
  }

  for (i = 0; i < DOODLEBUG_POPULATION; i++) {
    Position pos = getRandomPos();
    while (!field->isEmpty(pos)) {
      pos = getRandomPos();
    }

    Organism* doodlebug = new Doodlebug(field, pos);
  }

  field->print();

  string input = "";
  while (1) {
    cout << "Press any key to continue or exit to stop..." << endl;
    cin >> input;
    if (input == "exit") {
      cout << "Ending program..." << endl;
      break;
    } else {
      field->step('X');
      field->step('O');
      field->print();
    }
  }

  return 0;
}
