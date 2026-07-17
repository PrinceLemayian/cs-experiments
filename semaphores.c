#include <stdio.h>

// Simple semaphore structure
typedef struct {
  int value;
} Semaphore;

// Wait (P operation)
void wait(Semaphore *s) {
  s->value--;

  if (s->value < 0) {
    // Add this process to the semaphore queue
    // block();   // Suspend the process
    printf("Process blocked.\n");
  }
}

// Signal (V operation)
void signal(Semaphore *s) {
  s->value++;

  if (s->value <= 0) {
    // Remove a process from the semaphore queue
    // unblock();   // Wake up the process
    printf("Process unblocked.\n");
  }
}

int main() {
  Semaphore mutex = {1}; // Binary semaphore

  wait(&mutex);
  printf("Critical Section\n");
  signal(&mutex);

  return 0;
}
