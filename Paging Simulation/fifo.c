/* ============================================================================
 * Christopher Boyd / Lab 04 / 29 March 2020
 * ----------------------------------------------------------------------------
 * Fifo
 * Main function &
 * Implementation details for first-in first-out algorithm
 *-------------------------------------------------------------------------- */

#include "queue.h"
#include <string.h>

// PROTOTYPES
bool is_num(char *chk);

int main(int argc, char *argv[])
{

  // IDENTIFIERS, ETC
  int buf_size = -1;

  // Check if argv[1] was supplied, else end process
  if (argv[1] != NULL && (argc > 1 && argc < 3))
  {
      buf_size = (atoi(argv[1]));
      // Error: Non-number value used for argv[1]
      if (buf_size <= 0)
      {
        fprintf(stderr, "Error: buffer must be type int greater than 0\n");
        return 1;
      }
  }
  else
  {
    fprintf(stderr, "Format: fifo_test buffer_size\n");
    return 1;
  }

  queue *new_q;
  new_q = malloc(sizeof(queue));
  initialize(new_q, buf_size);
  char file_in[5];
  int tempInt;
  int pagedFiles = 0;
  int totalFiles = 0;

  // Get numbers from stdin
  while (fgets(file_in, sizeof(file_in), stdin))
  {
    tempInt = atoi(file_in);

    // Abort program if stdin contains alphabet characters
    if (is_num(file_in) == false)
    {
      fprintf(stderr, "Fatal error, string contains spaces or non-numeric characters!\n");
      return(1);
    }

    /*
    printf("Paged: %d  |", pagedFiles);
    print_list(new_q->front);
    */

    // Simulate paging if tempInt absent in current queue
    if (check_size(new_q) == buf_size)
    {
      if (traverse(new_q, tempInt) == false)
      {
        dequeue(new_q);
        enqueue(new_q, tempInt);
        pagedFiles++;
      }
    }
    else
    {
      // Queue hasn't filled yet. Don't dequeue any contents
      if (traverse(new_q, tempInt) == false)
      {
        enqueue(new_q, tempInt);
        pagedFiles++;
      }
    }

    totalFiles++;
  }

  printf("%d total page faults for %d total blocks\n", pagedFiles, totalFiles);

  return(0);
} // End main

bool is_num(char *chk)
{
  for (int i = 0; i < strlen(chk) - 1; i++)
  {
    if(chk[i] < 48 || chk[i] > 57)
    {
      // ASCII vals not numbers. Return false
      return false;
    }
    else if(chk[i] == 32)
    {
      // No white spaces accepted
      return false;
    }
  }

  return true;
} // end is_num_or_trail
