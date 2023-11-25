#include <stdlib.h>
#include <stdio.h>
#include "graph.h"

void GraphProcessing (Graph *g, int s)
{
   int n = g->num_vertices;
   Edge *p;
   int max = 0;
   int min = 1 << 30;
   double sum = 0;
   int nr=-1;
   for (int i = s; i < g->num_vertices; i++) {
      if (g->v[i].pred==-1) {
         nr++;
         continue;
      }
      else{
         printf("Distance is %d\n", g->v[i].d);
         sum = sum + g->v[i].d;
         if (g->v[i].d<min) {
            min = g->v[i].d;
         }
         if (g->v[i].d>max) {
            max = g->v[i].d;
         }
      }
   }
   double avg = sum / (g->num_vertices-nr);
   printf("min: %d, max: %d, avg: %f, total number of vertices: %d, number of unreachable vertices: %d", min, max, avg, n, nr);
}


int main (int argc, char *argv[])
{
   Graph *g;
   int s;

   if (argc != 3)
   {
      printf ("usage: %s <graph_file> <source_vertex>\n");
      return 1;
   }

   g = ReadGraphFile (argv[1]);

   if (g != NULL)
   {
       s = atoi (argv[2]);

       BFS (g, s);

       GraphProcessing (g, s);
   }
}