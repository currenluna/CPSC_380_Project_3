#include "SeeSaw.h"

/* Curren Taber & Joan Karstrom
 * Professor Hansen
 * CPSC 380-01
 * Project 3: See-Saw Simulator
 */

// Main
int main(int argc, char* argv[]) {

  SeeSaw* s = new SeeSaw();
  s->RunSimulation();

  // // Check for file input
  // if (argc > 1) {
  //   Sudoku* s = new Sudoku(argv[1]);
  //   s->FindCoordinates();
  // } else {
  //   cout << "No file provided." << endl;
  // }
  return 0;
}
