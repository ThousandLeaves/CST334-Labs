/* ============================================================================
 * Christopher Boyd / Lab 04 / 29 March 2020
 * ----------------------------------------------------------------------------
 * Node
 * Implementation details for node
 *-------------------------------------------------------------------------- */
 #include "node.h"

int node_peek(node *check_node)
{
  return (check_node->data);
}

node* node_next(node *next_node)
{
  return (next_node->next);
}

void print_list(node *n)
{
  node *current = n;

  printf("List contents: ");
  while (current != NULL)
  {
    printf("%d, ", current->data);
    current = current->next;
  }
  printf("\n");
}
