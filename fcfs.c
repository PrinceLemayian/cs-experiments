#include <stdio.h>

int main() {
  int n;

  printf("Enter number of processes: ");
  scanf("%d", &n);

  int bt[n], wt[n], tat[n];
  float avgWT = 0, avgTAT = 0;

  // Input burst times
  for (int i = 0; i < n; i++) {
    printf("Enter Burst Time for Process P%d: ", i + 1);
    scanf("%d", &bt[i]);
  }

  // Calculate waiting times
  wt[0] = 0;
  for (int i = 1; i < n; i++) {
    wt[i] = wt[i - 1] + bt[i - 1];
  }

  // Calculate turnaround times
  for (int i = 0; i < n; i++) {
    tat[i] = wt[i] + bt[i];
    avgWT += wt[i];
    avgTAT += tat[i];
  }

  // Display results
  printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
  for (int i = 0; i < n; i++) {
    printf("P%d\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tat[i]);
  }

  // Calculate averages
  avgWT /= n;
  avgTAT /= n;

  printf("\nAverage Waiting Time = %.2f", avgWT);
  printf("\nAverage Turnaround Time = %.2f\n", avgTAT);

  return 0;
}
