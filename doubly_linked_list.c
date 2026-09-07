#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *prev;
  struct Node *next;
} Node;

int main(void) {
  // Create three nodes
  Node *first = malloc(sizeof(Node));
  Node *second = malloc(sizeof(Node));
  Node *third = malloc(sizeof(Node));

  // Store data
  first->data = 10;
  second->data = 20;
  third->data = 30;

  // Connect forward
  first->next = second;
  second->next = third;
  third->next = NULL;

  // Connect backward
  first->prev = NULL;
  second->prev = first;
  third->prev = second;

  // Traverse forward
  Node *current = first;

  printf("Forward: ");

  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }

  // Traverse backward
  current = third;

  printf("\nBackward: ");

  while (current != NULL) {
    printf("%d ", current->data);
    current = current->prev;
  }

  // Free memory
  free(first);
  free(second);
  free(third);

  return 0;
}
