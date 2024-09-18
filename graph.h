#include <stdio.h>
#include <stdlib.h>

typedef struct vertex {
  int value;
  struct vertex **linked_vertices;
} IntGraphVertex;

typedef struct graph{
  IntGraphVertex *vertices;
} Graph;

Graph *create_graph(int num_vertices){
  Graph *graph = malloc(sizeof(Graph));
  graph->vertices = malloc(sizeof(IntGraphVertex) * num_vertices);
  for(int i = 0; i < num_vertices; i++){
    graph->vertices[i].value = i;
    graph->vertices[i].linked_vertices = NULL;
  }
  return graph;
}


void linkNewVertex(Graph *graph, int vertex_index, int linked_vertex_index){
  IntGraphVertex *vertex = &graph->vertices[vertex_index];
  IntGraphVertex *linked_vertex = &graph->vertices[linked_vertex_index];
  vertex->linked_vertices = realloc(vertex->linked_vertices, sizeof(IntGraphVertex) * (vertex->linked_vertices + 1) 
    
}
