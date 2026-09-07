#include <stdio.h>

void insertionSort(int arr[], int size) {
  for (int i = 1; i < size; i++) {
    int key = arr[i];
    int j = i - 1;

    // Move elements greater than key
    // one position to the right
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j--;
    }

    // Insert key into its correct position
    arr[j + 1] = key;
  }
}

int main(void) {
  int numbers[] = {64, 25, 12, 22, 11};
  int size = sizeof(numbers) / sizeof(numbers[0]);

  insertionSort(numbers, size);

  printf("Sorted array: ");

  for (int i = 0; i < size; i++) {
    printf("%d ", numbers[i]);
  }

  printf("\n");

  return 0;
}
