#include <stdio.h>

void selectionSort(int low, int high);

int a[25];

int main(void) {
  int num, i;

  printf("Enter the number of elements (max 25): ");
  scanf("%d", &num);

  if (num < 1 || num > 25) {
    printf("Invalid number of elements.\n");
    return 1;
  }

  printf("Enter the elements:\n");
  for (i = 0; i < num; i++)
    scanf("%d", &a[i]);

  selectionSort(0, num - 1);

  printf("\nThe elements after sorting are: ");
  for (i = 0; i < num; i++)
    printf("%d ", a[i]);

  printf("\n");

  return 0;
}

void selectionSort(int low, int high) {
  int i, j, temp, minindex;

  for (i = low; i <= high; i++) {
    minindex = i;

    for (j = i + 1; j <= high; j++) {
      if (a[j] < a[minindex])
        minindex = j;
    }

    temp = a[i];
    a[i] = a[minindex];
    a[minindex] = temp;
  }
}
