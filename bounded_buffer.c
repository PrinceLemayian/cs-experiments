/*
 * ============================================================
 *  Bounded Buffer — Shared Memory / Pointer-Based
 *  Classic Producer-Consumer Problem (OS Concepts)
 *
 *  Simulates two "processes" as POSIX threads sharing a
 *  single circular buffer in memory.
 *
 *  Key constraint: only (BUFFER_SIZE - 1) slots are usable
 *  so that FULL and EMPTY states can be told apart.
 * ============================================================
 */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h> /* sleep() */

/* ── 1. BUFFER SETUP ─────────────────────────────────────── */

#define BUFFER_SIZE 10 /* total slots; only 9 are usable */

typedef struct {
  int id;    /* which item number this is */
  int value; /* the actual data payload    */
} item;

/* Shared memory visible to BOTH producer and consumer */
item buffer[BUFFER_SIZE];
int in = 0;  /* next FREE slot  — producer writes here  */
int out = 0; /* next FULL slot  — consumer reads here   */

/* ── 2. HELPER: visualise the buffer state ───────────────── */

void print_buffer(const char *actor) {
  printf("  [%s] buffer: [ ", actor);
  for (int i = 0; i < BUFFER_SIZE; i++) {
    if (i == in && i == out)
      printf("IO "); /* both pointers same slot */
    else if (i == in)
      printf("I  "); /* next write position     */
    else if (i == out)
      printf("O  "); /* next read  position     */
    else if (        /* slot holds live data?   */
             (in > out && i >= out && i < in) ||
             (in < out && (i >= out || i < in)) || (in == out)) {
      /* simplification: mark non-pointer slots with their value */
      printf("%2d ", buffer[i].value);
    } else {
      printf(" _ ");
    }
  }
  printf("]\n");
}

/* ── 3. PRODUCER THREAD ──────────────────────────────────── */

void *producer(void *arg) {
  int produced_count = 0;

  while (produced_count < 15) { /* produce 15 items then stop */

    /* Create a new item to insert */
    item nextProduced;
    nextProduced.id = produced_count;
    nextProduced.value = produced_count * 10; /* e.g. 0, 10, 20, 30 … */

    /* BUSY WAIT — spin until there is at least one free slot
     *
     *   Full condition:  (in + 1) % BUFFER_SIZE == out
     *   If true the buffer is full; we loop doing nothing.
     */
    int spun = 0;
    while (((in + 1) % BUFFER_SIZE) == out) {
      if (!spun)
        printf("  [PRODUCER] Buffer FULL — waiting...\n");
      spun = 1;
      usleep(5000); /* short sleep to avoid hammering the CPU in demo */
    }

    /* Write the item into the next free slot */
    buffer[in] = nextProduced;

    printf("  [PRODUCER] Wrote  item %2d (value=%3d) → slot %d\n",
           nextProduced.id, nextProduced.value, in);

    /* Advance the IN pointer (wrap around with modulo) */
    in = (in + 1) % BUFFER_SIZE;

    print_buffer("PRODUCER");
    produced_count++;
    usleep(80000); /* slow the producer down a little for readability */
  }

  printf("\n  [PRODUCER] Done producing.\n");
  return NULL;
}

/* ── 4. CONSUMER THREAD ──────────────────────────────────── */

void *consumer(void *arg) {
  int consumed_count = 0;

  while (consumed_count < 15) { /* consume same 15 items */

    /* BUSY WAIT — spin until there is at least one full slot
     *
     *   Empty condition:  in == out
     *   If true the buffer is empty; we loop doing nothing.
     */
    int spun = 0;
    while (in == out) {
      if (!spun)
        printf("  [CONSUMER] Buffer EMPTY — waiting...\n");
      spun = 1;
      usleep(5000);
    }

    /* Read the item from the next full slot */
    item nextConsumed = buffer[out];

    printf("  [CONSUMER] Read   item %2d (value=%3d) ← slot %d\n",
           nextConsumed.id, nextConsumed.value, out);

    /* Advance the OUT pointer (wrap around with modulo) */
    out = (out + 1) % BUFFER_SIZE;

    print_buffer("CONSUMER");

    /* "Use" the item — here we just print it */
    printf("  [CONSUMER] Consumed value: %d\n\n", nextConsumed.value);

    consumed_count++;
    usleep(150000); /* consumer is slower than producer → triggers FULL */
  }

  printf("  [CONSUMER] Done consuming.\n");
  return NULL;
}

/* ── 5. MAIN ─────────────────────────────────────────────── */

int main(void) {
  printf("=== Bounded Buffer Demo ===\n");
  printf("Buffer size : %d slots total, %d usable\n\n", BUFFER_SIZE,
         BUFFER_SIZE - 1);

  pthread_t prod_thread, cons_thread;

  /* Launch producer and consumer as concurrent threads */
  pthread_create(&prod_thread, NULL, producer, NULL);
  pthread_create(&cons_thread, NULL, consumer, NULL);

  /* Wait for both to finish */
  pthread_join(prod_thread, NULL);
  pthread_join(cons_thread, NULL);

  printf("\n=== Simulation complete ===\n");
  return 0;
}
