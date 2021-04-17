#include "SeeSaw.h"

/* Curren Taber & Joan Karstrom
 * Professor Hansen
 * CPSC 380-01
 * Project 3: See-Saw Simulator
 */

sem_t* semFred;
sem_t* semWilma;
bool fredsTurn = true;
double fredsHeight = 1;
double wilmasHeight = 7;

// Constructor
SeeSaw::SeeSaw() {}

// Behavior for Fred
void* SeeSaw::FredSee(void* arg) {

  // TODO: Manage Fred's height and print current height
  for (int i = 0; i < ITERATION_COUNT; i++) {
    // Critical Section
    sem_wait(semWilma);
    cout << "Fred's turn" << endl;
    sem_post(semFred);
    usleep(1000000); // Sleep for 1 second
  }

  pthread_exit(0);
}

// Behavior for Wilma
void* SeeSaw::WilmaSaw(void* arg) {

  // TODO: Manage Wilma's height and print current height
  for (int i = 0; i < ITERATION_COUNT; i++) {
    // Critical Section
    sem_wait(semFred);
    cout << "Wilma's turn" << endl;
    sem_post(semWilma);
    usleep(1000000); // Sleep for 1 second
  }

  pthread_exit(0);
}

// Runs the See-Saw Simulation
void SeeSaw::RunSimulation() {



  sem_unlink(SEM_FRED_NAME);
  semFred = sem_open(SEM_FRED_NAME, O_CREAT, 0777, 0);
  if (semFred == SEM_FAILED) {
    cout << "Failed to open semaphore for Fred" << endl;
    exit(-1);
  }

  sem_unlink(SEM_WILMA_NAME);
  semWilma = sem_open(SEM_WILMA_NAME, O_CREAT, 0777, 1);
  if (semWilma == SEM_FAILED) {
    cout << "Failed to open semaphore for Wilma" << endl;
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

  sem_close(semFred);
  sem_close(semWilma);
}
