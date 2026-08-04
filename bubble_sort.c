#include <stdio.h>

void bubblesort(int x[], int n) {
  int i, j, t;

  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - i - 1; j++) {
      if (x[j] > x[j + 1]) {
        t = x[j];
        x[j] = x[j + 1];
        x[j + 1] = t;
      }
    }
  }
}

int main(void) {
  int i, n, x[25];

  printf("Enter the number of elements (max 25): ");
  scanf("%d", &n);

  if (n < 1 || n > 25) {
    printf("Invalid number of elements.\n");
    return 1;
  }

  printf("Enter the elements:\n");
  for (i = 0; i < n; i++) {
    scanf("%d,", &x[i]);
  }

  bubblesort(x, n);

  printf("Array elements after sorting:\n");
  for (i = 0; i < n; i++) {
    printf("%d, ", x[i]);
  }

  printf("\n");

  return 0;
}
