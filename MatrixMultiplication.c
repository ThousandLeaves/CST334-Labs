// Name: Christopher Boyd
// Date: April 6, 2020
// Title: Lab5 - matrix task
// Description: Computes the dot product of matrices A and B as matrix C.
// One thread is created per row.
// ----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

// Defines matrix dimensions of 1024x1024
#define N 1024
#define M 1024
#define L 1024

pthread_t threads[N];
pthread_mutex_t lock;
void *con(void*);

double matrixA[N][M];
double matrixB[M][L];
double matrixC[N][L];

int main()
{
  // Initialize lock
  pthread_mutex_init(&lock, NULL);

  // Fill 2d arrays with rand values:
  srand(time(NULL));
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      matrixA[i][j] = rand();
    }
  }

  for (int i = 0; i < M; i++)
  {
    for (int j = 0; j < L; j++)
    {
      matrixB[i][j] = rand();
    }
  }

  int i;
  int tNum = 0;

  // Create threads
  for (i = 0; i < N; i++)
  {
    pthread_create(&threads[i], NULL, con, &tNum);
  }

  // Wait for all threads to complete their processing
  for (i = 0; i < N; i++)
  {
    pthread_join(threads[i], NULL);
  }

  printf("\nOperations complete! Here is matrix C:\n");

  // Print results of matrix multiplication
  for (int l = 0; l < N; l++)
  {
    for (int m = 0; m < L; m++)
    {
      printf(" [ %.*f ] ", 0, matrixC[l][m]);
    }
    printf("\n");
  }

  return 0;
}

void *con(void* args)
{
  // args value represents the current column num to operate on.
  // Each thread requires a UNIQUE value. This is a critical section.
  pthread_mutex_lock(&lock);

  // Set alias for easier use
  int *row = (int *) args;
  // Loop performs math on the matrices to create matrixC
  for (int j = 0; j < L; j++)
  {
    double temp = 0;
    for (int k = 0; k < M; k++)
    {
      temp += matrixA[*row][k] * matrixB[k][j];
    }
    matrixC[*row][j] = temp;
  }
  *row += 1;
  pthread_mutex_unlock(&lock);

  return 0;
}
