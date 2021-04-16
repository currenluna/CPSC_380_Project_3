#include "SeeSaw.h"

/* Curren Taber & Joan Karstrom
 * Professor Hansen
 * CPSC 380-01
 * Project 3: See-Saw Simulator
 */

// Global Variables
bool bottomReached;
int height;

// Constructor
SeeSaw::SeeSaw() {
  bottomReached = true;
  height = 1;
}

// Behavior for Fred
void* SeeSaw::FredSee(void* arg) {

  // TODO: Manage Fred's height and print current height

  pthread_exit(0);
}

// Behavior for Wilma
void* SeeSaw::WilmaSaw(void* arg) {

  // TODO: Manage Wilma's height and print current height

  pthread_exit(0);
}
