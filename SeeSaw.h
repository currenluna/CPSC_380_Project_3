#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
using namespace std;

/* Curren Taber & Joan Karstrom
 * Professor Hansen
 * CPSC 380-01
 * Project 3: See-Saw Simulator
 */

// Number of runs
#define ITERATION_COUNT 10

class SeeSaw {
  public:
    SeeSaw(); // Constructor
    void RunSimulation(); // Runs the See-Saw Simulation
  private:
    static void* FredSee(void* arg); // Behavior for Fred
    static void* WilmaSaw(void* arg); // Behavior for Wilma
};
