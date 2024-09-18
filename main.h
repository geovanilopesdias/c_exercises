#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main(void) {
int num_linked_vertices = 5;  // Example number of linked vertices
    struct Vertex *vertex = malloc(sizeof(struct Vertex));
    vertex -> linked_vertices = malloc(num_linked_vertices * sizeof(struct Vertex *));

    free(vertex->linked_vertices);
    free(vertex);

    return 0;
}
