#include <stdio.h>

int main() {
  int n, quantum;
  int burst[10], remaining[10];
  int waiting[10] = {0}, turnaround[10];
  int time = 0, done;

  printf("Enter number of processes: ");
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    printf("Burst time of P%d: ", i + 1);
    scanf("%d", &burst[i]);
    remaining[i] = burst[i];
  }

  printf("Enter time quantum: ");
  scanf("%d", &quantum);

  printf("\nExecution Order:\n");

  do {
    done = 1;

    for (int i = 0; i < n; i++) {
      if (remaining[i] > 0) {
        done = 0;

        if (remaining[i] > quantum) {
          printf("Time %2d -> %2d : P%d\n", time, time + quantum, i + 1);
          time += quantum;
          remaining[i] -= quantum;
        } else {
          printf("Time %2d -> %2d : P%d\n", time, time + remaining[i], i + 1);

          time += remaining[i];
          waiting[i] = time - burst[i];
          remaining[i] = 0;
        }
      }
    }

  } while (!done);

  printf("\nProcess\tBurst\tWaiting\tTurnaround\n");

  float totalWT = 0, totalTAT = 0;

  for (int i = 0; i < n; i++) {
    turnaround[i] = waiting[i] + burst[i];
    totalWT += waiting[i];
    totalTAT += turnaround[i];

    printf("P%d\t%d\t%d\t%d\n", i + 1, burst[i], waiting[i], turnaround[i]);
  }

  printf("\nAverage Waiting Time = %.2f", totalWT / n);
  printf("\nAverage Turnaround Time = %.2f\n", totalTAT / n);

  return 0;
}
