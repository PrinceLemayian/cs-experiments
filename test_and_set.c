#include <stdbool.h>

bool lock = false;

// Conceptual TestAndSet (not actually atomic)
bool TestAndSet(bool *target) {
  bool rv = *target;
  *target = true;
  return rv;
}

void process() {
  do {
    while (TestAndSet(&lock))
      ; // Busy wait

    // Critical Section

    lock = false;

    // Remainder Section

  } while (1);
}
