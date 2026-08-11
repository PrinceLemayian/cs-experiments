#include <stdio.h>

#define SIZE 5

int queue[SIZE];
int front = 0;
int rear = -1;

/* Add an element to the rear */
void enqueue(int value) {
  if (isFull()) {
    printf("Queue is full\n");
    return;
  }

  rear++;
  queue[rear] = value;
}

/* Remove an element from the front */
void dequeue() {
  if (isEmpty()) {
    printf("Queue is empty\n");
    return;
  }

  printf("Removed: %d\n", queue[front]);
  front++;
}

/* Get the front element */
int peek() {
  if (isEmpty()) {
    printf("Queue is empty\n");
    return -1;
  }

  return queue[front];
}

/* Get the rear element */
int rearValue() {
  if (isEmpty()) {
    printf("Queue is empty\n");
    return -1;
  }

  return queue[rear];
}

/* Check whether queue is empty */
int isEmpty() { return front > rear; }

/* Check whether queue is full */
int isFull() { return rear == SIZE - 1; }

/* Get number of elements */
int size() {
  if (isEmpty()) {
    return 0;
  }

  return rear - front + 1;
}

/* Search for a value */
int search(int value) {
  for (int i = front; i <= rear; i++) {
    if (queue[i] == value) {
      return 1;
    }
  }

  return 0;
}

/* Remove all elements */
void clear() {
  front = 0;
  rear = -1;
}

/* Display queue */
void display() {
  if (isEmpty()) {
    printf("Queue is empty\n");
    return;
  }

  for (int i = front; i <= rear; i++) {
    printf("%d ", queue[i]);
  }

  printf("\n");
}

int main() {
  enqueue(10);
  enqueue(20);
  enqueue(30);

  display();

  printf("Front: %d\n", peek());
  printf("Rear: %d\n", rearValue());
  printf("Size: %d\n", size());

  if (search(20)) {
    printf("20 found\n");
  }

  dequeue();

  display();

  printf("Size: %d\n", size());

  clear();

  display();

  return 0;
}
