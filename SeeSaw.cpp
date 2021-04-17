#include "SeeSaw.h"

/* Curren Taber & Joan Karstrom
 * Professor Hansen
 * CPSC 380-01
 * Project 3: See-Saw Simulator
 */

const char* turnName = "turn";
const char* heightName = "height";

sem_t* turn;
sem_t* height;

bool fredsTurn = true;

// Constructor
SeeSaw::SeeSaw() {}

// Behavior for Fred
void* SeeSaw::FredSee(void* arg) {

  // TODO: Manage Fred's height and print current height
  for (int i = 0; i < ITERATION_COUNT; i++) {
    // Critical Section
    sem_wait(turn);
    cout << "Fred's turn" << endl;
    sem_post(turn);
    usleep(1000000); // Sleep for 1 second
  }

  pthread_exit(0);
}

// Behavior for Wilma
void* SeeSaw::WilmaSaw(void* arg) {

  // TODO: Manage Wilma's height and print current height
  for (int i = 0; i < ITERATION_COUNT; i++) {
    // Critical Section
    sem_wait(turn);
    cout << "Wilma's turn" << endl;
    sem_post(turn);
    usleep(1000000); // Sleep for 1 second
  }

  pthread_exit(0);
}

// Runs the See-Saw Simulation
void SeeSaw::RunSimulation() {

  sem_unlink(turnName);
  turn = sem_open(turnName, O_CREAT, 0777, 1);
  if (turn == SEM_FAILED) {
    cout << "Failed to open semaphore for turn" << endl;
    exit(-1);
  }

  sem_unlink(heightName);
  height = sem_open(heightName, O_CREAT, 0777, 10);
  if (turn == SEM_FAILED) {
    cout << "Failed to open semaphore for height" << endl;
    exit(-1);
  }

  // Creating child threads for Fred and Wilma
  pthread_t tid_fred;
  pthread_t tid_wilma;

  pthread_create(&tid_fred, NULL, &FredSee, NULL);
  pthread_create(&tid_wilma, NULL, &WilmaSaw, NULL);

  // Joining the child threads with this thread
  pthread_join(tid_fred, NULL);
  pthread_join(tid_wilma, NULL);

  sem_close(turn);
}
