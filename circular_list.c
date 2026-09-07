#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
} Node;

void insertEnd(Node **head, int value) {
  Node *newNode = malloc(sizeof(Node));

  newNode->data = value;

  // If the list is empty
  if (*head == NULL) {
    newNode->next = newNode;
    *head = newNode;
    return;
  }

  Node *current = *head;

  // Find the last node
  while (current->next != *head) {
    current = current->next;
  }

  // Connect the new node
  current->next = newNode;
  newNode->next = *head;
}

void display(Node *head) {
  if (head == NULL) {
    printf("List is empty\n");
    return;
  }

  Node *current = head;

  do {
    printf("%d ", current->data);
    current = current->next;
  } while (current != head);

  printf("\n");
}

int main(void) {
  Node *head = NULL;

  insertEnd(&head, 10);
  insertEnd(&head, 20);
  insertEnd(&head, 30);

  display(head);

  return 0;
}
