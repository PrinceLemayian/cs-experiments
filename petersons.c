#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

volatile bool flag[2] = {false, false};
volatile int turn;

// Peterson's algorithm
void enter_critical(int i) {
  int j = 1 - i;

  flag[i] = true;
  turn = j;

  while (flag[j] && turn == j) {
    // Busy wait
  }
}

void leave_critical(int i) { flag[i] = false; }

void *process(void *arg) {
  int i = *(int *)arg;

  for (int k = 0; k < 5; k++) {
    // Entry section
    enter_critical(i);

    // Critical section
    printf("Process P%d is in the critical section.\n", i);
    sleep(1);

    // Exit section
    printf("Process P%d is leaving the critical section.\n", i);
    leave_critical(i);

    // Remainder section
    sleep(1);
  }

  return NULL;
}

int main() {
  pthread_t p0, p1;
  int id0 = 0, id1 = 1;

  pthread_create(&p0, NULL, process, &id0);
  pthread_create(&p1, NULL, process, &id1);

  pthread_join(p0, NULL);
  pthread_join(p1, NULL);

  return 0;
}
