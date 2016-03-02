#ifndef POSITION_H
#define POSITION_H

// Represents a direction from the perspective of an organism
enum Direction { NORTH, SOUTH, EAST, WEST };

// Represents a position on an xy-coordinate system
struct Position {
  int x;
  int y;
  Position(int x, int y) : x(x), y(y) {}
};

#endif
