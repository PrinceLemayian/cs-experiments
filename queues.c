#include <stdio.h>

#define SIZE 5

int queue[SIZE];
int front = 0;
int rear = -1;

void enqueue(int value) {
  if (rear == SIZE - 1) {
    printf("Queue is full\n");
    return;
  }

  rear++;
  queue[rear] = value;
}

void dequeue() {
  if (front > rear) {
    printf("Queue is empty\n");
    return;
  }

  printf("Removed: %d\n", queue[front]);
  front++;
}

int peek() {
  if (front > rear) {
    printf("Queue is empty\n");
    return -1;
  }

  return queue[front];
}

int isEmpty() { return front > rear; }

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

  dequeue();

  display();

  return 0;
}
