/* ============================================================================
 * Christopher Boyd / Lab 04 / 29 March 2020
 * ----------------------------------------------------------------------------
 * Node Header
 * Contains header information for node.c
 *-------------------------------------------------------------------------- */

#ifndef _NODE_H
#define _NODE_H

#include <stdio.h>
#include <stdlib.h>

// Node def
typedef struct node
{
    int data;
    // If NULL then reached end of linked list
    struct node *next;
} node;

// Returns value of current node
int node_peek(node *n);

// Returns a node* of following node
node* node_next(node *n);

// Prints the full current list of nodes for debugging
void print_list(node *n);

#endif
