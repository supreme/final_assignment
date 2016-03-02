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
#define FIELD_WIDTH (5)
#define FIELD_HEIGHT (5)

/**

*/
int main( ) {
  Field* field; // Holds a pointer to the playing field object
  srand(time(NULL));
  printf("Playing the ants vs. doodlebugs game.\n");

  field = new Field(FIELD_WIDTH, FIELD_HEIGHT);

  // Put some Organisms on the field
  Organism* org1 = new Doodlebug(field, 2, 3);
  Organism* d1 = new Doodlebug(field, 1, 1);
  Organism* d2 = new Doodlebug(field, 2, 4);
  Organism* org2 = new Ant(field, 4, 1);
  Organism* ant1 = new Ant(field, 3, 3);
  Organism* ant2 = new Ant(field, 2, 2);
  Organism* ant3 = new Ant(field, 4, 3);

  Position pos = Position(7, 7);
  cout << pos.x << " " << pos.y << endl;

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
