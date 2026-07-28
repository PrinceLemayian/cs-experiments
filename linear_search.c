#include <stdio.h>

int main() {
  int number[25], n, data, i;
  int flag = 0;

  printf("Enter the number of elements: ");
  scanf("%d", &n);

  printf("Enter the elements:\n");
  for (i = 0; i < n; i++) {
    scanf("%d, ", &number[i]);
  }

  printf("Enter the element to search: ");
  scanf("%d", &data);

  for (i = 0; i < n; i++) {
    if (number[i] == data) {
      flag = 1;
      break;
    }
  }

  if (flag == 1)
    printf("Data found at position %d\n", i + 1);
  else
    printf("Data not found\n");

  return 0;
}
