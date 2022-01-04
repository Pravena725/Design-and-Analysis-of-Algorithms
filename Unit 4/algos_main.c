#include<stdio.h>
#include<stdlib.h>
#include "PES2UG19CS076_H.h"

int main()
{
	Graph*g;
	g=file();
 
    	Heap*h;
	h=create(g->n); 

    	g=Dijkstra(g,h);
    	output(g);
}