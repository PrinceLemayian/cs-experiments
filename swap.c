#include <stdbool.h>

bool lock = false;

// Conceptual Swap (not actually atomic)
void Swap(bool *a, bool *b) {
  bool temp = *a;
  *a = *b;
  *b = temp;
}

void process() {
  bool key;

  do {
    key = true;

    // Busy wait
    while (key == true)
      Swap(&lock, &key);

    // ===== Critical Section =====

    // Release the lock
    lock = false;

    // ===== Remainder Section =====

  } while (1);
}

int main() {
  process();
  return 0;
}
