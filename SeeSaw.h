#include <iostream>
#include <fstream>
#include <sstream>
#include <pthread.h>
#include <unordered_set>
using namespace std;

/* Curren Taber & Joan Karstrom
 * Professor Hansen
 * CPSC 380-01
 * Project 3: See-Saw Simulator
 */

// Number of runs
#define N 10

// Global Variables
extern bool bottomReached; // True if the bottom of the see-saw is reached
extern int height; // Current height of

class SeeSaw {
  public:
    SeeSaw(); // Constructor
  private:
    static void* FredSee(void* arg); // Behavior for Fred
    static void* WilmaSaw(void* arg); // Behavior for Wilma
};
