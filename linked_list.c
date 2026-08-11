#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

void display(struct Node *head) {
  struct Node *current = head;

  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }

  printf("\n");
}

int main() {
  struct Node *head = NULL;

  struct Node *first = malloc(sizeof(struct Node));
  struct Node *second = malloc(sizeof(struct Node));
  struct Node *third = malloc(sizeof(struct Node));

  first->data = 10;
  first->next = second;

  second->data = 20;
  second->next = third;

  third->data = 30;
  third->next = NULL;

  head = first;

  display(head);

  return 0;
}
