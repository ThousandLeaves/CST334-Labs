// ==========================================================================
// Christopher Boyd
// 13 April, 2020
// Lab 06 - Task 2
// Description: Semaphore example that produces and consumes letters of
// the alphabet
// --------------------------------------------------------------------------

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define SIZE 26

char buffer[SIZE];

sem_t empty, full, mutex;
pthread_t tProducer, tConsumer;

// Helpers to put and get chars from buffers
void put(int val)
{
  // Setting buffer position to val - 65 (ASCII A)
  // This will fill up the buffer from A to Z
  int element = val - 65;
  buffer[element] = val;
}

char get(int val)
{
  char temp = buffer[val];
  // Consume & clear buffer (set to null char)
  buffer[val] = 0;
  return temp;
}

// Adds an item to buffer
void *producer(void *arg)
{
    printf("Populating buffer...\n");
  // Loop to fill buffer with A-Z using ASCII vals
  for (int i = 65; i <= 90; i++)
  {
    sem_wait(&empty);
    sem_wait(&mutex);
    // CRITICAL SECTION
    put(i);
    sem_post(&mutex);
    sem_post(&full);
  }
}

// Gets an item from buffer
void *consumer(void *arg)
{
  printf("Consuming...\nOutput: ");
  // Loop to take item from buffer and clear it
  for (int i = 0; i <= 25; i++)
  {
    char temp;
    sem_wait(&full);
    sem_wait(&mutex);
    // CRITICAL SECTION
    temp = get(i);
    sem_post(&mutex);
    sem_post(&empty);
    printf("%c, ", temp);
  }
  printf("\n");
}

// Initialize all data structures
int main()
{
  sem_init(&empty, 0, 1);
  sem_init(&full, 0, 0);
  sem_init(&mutex, 0, 1);

  pthread_create(&tProducer, NULL, producer, NULL);
  pthread_create(&tConsumer, NULL, consumer, NULL);

  // Wait for threads to complete
  pthread_join(tProducer, NULL);
  pthread_join(tConsumer, NULL);

  printf("Done with thread operations.\n");

  sem_destroy(&mutex);
  sem_destroy(&empty);
  sem_destroy(&full);
  return 0;
}
