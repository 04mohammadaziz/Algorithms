#include <stdlib.h>
#include <stdio.h>
#include "graph.h"

void GraphProcessing (Graph *g, int s)
{
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

