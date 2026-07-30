#include <stdio.h>

int main() {
  int pages[] = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5};
  int n = 12;

  int frames;
  printf("Enter number of page frames: ");
  scanf("%d", &frames);

  int memory[frames];
  int faults = 0;
  int pointer = 0;

  // Initialize frames as empty
  for (int i = 0; i < frames; i++)
    memory[i] = -1;

  printf("\nPage\tFrames\n");

  for (int i = 0; i < n; i++) {
    int page = pages[i];
    int found = 0;

    // Check if page already exists
    for (int j = 0; j < frames; j++) {
      if (memory[j] == page) {
        found = 1;
        break;
      }
    }

    // Page fault
    if (!found) {
      memory[pointer] = page;
      pointer = (pointer + 1) % frames;
      faults++;
    }

    // Display frame contents
    printf("%d\t", page);
    for (int j = 0; j < frames; j++) {
      if (memory[j] == -1)
        printf("- ");
      else
        printf("%d ", memory[j]);
    }

    if (!found)
      printf("Fault");

    printf("\n");
  }

  printf("\nTotal Page Faults = %d\n", faults);

  return 0;
}
