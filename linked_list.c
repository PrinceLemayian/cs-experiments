#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

/* Display all nodes */
void display(struct Node *head) {
  struct Node *current = head;

  while (current != NULL) {
    printf("%d -> ", current->data);
    current = current->next;
  }

  printf("NULL\n");
}

/* Insert a node at the beginning */
void insertFront(struct Node **head, int value) {
  struct Node *newNode = malloc(sizeof(struct Node));

  if (newNode == NULL) {
    printf("Memory allocation failed\n");
    return;
  }

  newNode->data = value;
  newNode->next = *head;

  *head = newNode;
}

/* Insert a node at the end */
void insertEnd(struct Node **head, int value) {
  struct Node *newNode = malloc(sizeof(struct Node));

  if (newNode == NULL) {
    printf("Memory allocation failed\n");
    return;
  }

  newNode->data = value;
  newNode->next = NULL;

  /* If list is empty */
  if (*head == NULL) {
    *head = newNode;
    return;
  }

  struct Node *current = *head;

  while (current->next != NULL) {
    current = current->next;
  }

  current->next = newNode;
}

/* Delete the first node */
void deleteFront(struct Node **head) {
  if (*head == NULL) {
    printf("List is empty\n");
    return;
  }

  struct Node *temp = *head;

  *head = (*head)->next;

  free(temp);
}

/* Delete the last node */
void deleteEnd(struct Node **head) {
  if (*head == NULL) {
    printf("List is empty\n");
    return;
  }

  /* Only one node */
  if ((*head)->next == NULL) {
    free(*head);
    *head = NULL;
    return;
  }

  struct Node *current = *head;

  /* Find the second-to-last node */
  while (current->next->next != NULL) {
    current = current->next;
  }

  free(current->next);
  current->next = NULL;
}

/* Search for a value */
int search(struct Node *head, int value) {
  struct Node *current = head;

  while (current != NULL) {
    if (current->data == value) {
      return 1;
    }

    current = current->next;
  }

  return 0;
}

/* Delete the first node containing a value */
void deleteValue(struct Node **head, int value) {
  if (*head == NULL) {
    printf("List is empty\n");
    return;
  }

  /* If the value is in the first node */
  if ((*head)->data == value) {
    struct Node *temp = *head;

    *head = (*head)->next;

    free(temp);
    return;
  }

  struct Node *current = *head;

  while (current->next != NULL) {
    if (current->next->data == value) {
      struct Node *temp = current->next;

      current->next = temp->next;

      free(temp);
      return;
    }

    current = current->next;
  }

  printf("%d not found\n", value);
}

/* Free the entire list */
void freeList(struct Node **head) {
  struct Node *current = *head;

  while (current != NULL) {
    struct Node *temp = current;

    current = current->next;

    free(temp);
  }

  *head = NULL;
}

int main() {
  struct Node *head = NULL;

  /* Create initial nodes */
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

  /* Display */
  printf("Initial list: ");
  display(head);

  /* Insert at beginning */
  insertFront(&head, 5);

  printf("After insertFront(5): ");
  display(head);

  /* Insert at end */
  insertEnd(&head, 40);

  printf("After insertEnd(40): ");
  display(head);

  /* Search */
  if (search(head, 20)) {
    printf("20 was found\n");
  } else {
    printf("20 was not found\n");
  }

  /* Delete first */
  deleteFront(&head);

  printf("After deleteFront(): ");
  display(head);

  /* Delete last */
  deleteEnd(&head);

  printf("After deleteEnd(): ");
  display(head);

  /* Delete specific value */
  deleteValue(&head, 20);

  printf("After deleteValue(20): ");
  display(head);

  /* Free remaining nodes */
  freeList(&head);

  return 0;
}
