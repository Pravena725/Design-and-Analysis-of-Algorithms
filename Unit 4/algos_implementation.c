#include<stdio.h>
#include<stdlib.h>
#include "PES2UG19CS076_H.h"
#define inf INT_MAX   //max possible value

Graph* creategraph(int size)
{
	int i;
	Graph* g;
	g=(Graph*)malloc(sizeof(Graph));  
	g->n=size;
        g->graph=malloc(size * sizeof(Node));

        for (i=0;i<size;i++)
        {
		g->graph[i].head=NULL;
        	g->graph[i].prev=0;
        	g->graph[i].d=inf;
	}
        return g;
}

Head insert(Head head, int id, int weight)
{
	Node* new = malloc(sizeof(Node));
	new->next = NULL;
    	new->d = inf;
	new->prev= 0;
        new->id = id;
    	new->weight = weight;    	 

    	if (head.head == NULL) //list is empty
		head.head = new;  
    	else
    	{
        	Node*t = head.head;
        	while (t->next != NULL)
			t = t->next;        	
        	t->next = new;
    	}
    	return head;
}

Graph* file(void)
{ 
	size_t size = 1000;   
	FILE *fp;
    	fp=fopen("adjacencylist.txt","r");

    	if (fp == NULL)
	{
		printf("\nError in file opening\n");
        	return NULL;
	}     	

	char* num = malloc(sizeof(char)*1000);
    	int p=getline(&num,&size,fp);
    	Graph* g = creategraph(atoi(num)+1); 

    	while(p = getline(&num,&size,fp) != -1) //when it returns a line
    	{
		int weight,vertex;         
        	char* token = strtok(num, " ");
        	int node = atoi(token);        	

        	while (token != NULL)
        	{
			token = strtok(NULL," ");
            		if (token == NULL)
				break;

            		vertex=atoi(token);
            		token=strtok(NULL," ");

            		if (token == NULL)
                        	break;
            		weight=atoi(token);
            		g->graph[vertex]=insert(g->graph[vertex],node,weight);
        	}
	}
	return g;
}

Heap* create(int size)
{
	Heap*h=(Heap*)malloc(sizeof(Heap));
	h->n = size - 1;

    	h->heap=malloc((h->n + 1) * sizeof(Node));

    	for (int i = 0; i < h->n; i++)
    	{
        	h->heap[i].id = i + 1;
        	h->heap[i].d = inf;
        	h->heap[i].prev = 0;
    	}
    	return h;
}

Heap* delete(Heap* h, int* del)
{
	*del = h->heap[0].id;

    	for (int i = 0; i < (h->n - 1); i++)
		h->heap[i] = h->heap[i + 1];    
	h->n--;
    	return h;
}

Heap* update(Heap* h)
{
	Node t;
        for (int i = 0; i < h->n - 1; i++)
    	{
        	int swaps = 0;        
        	for (int j = 0; j < (h->n - i - 1); j++)
        	{
            		if (h->heap[j].d > h->heap[j + 1].d)
            		{
                		t = h->heap[j];
                		h->heap[j] = h->heap[j + 1];
                		h->heap[j + 1] = t;
                		swaps++;
            		}
        	}
        	if (swaps == 0)
			break;
	}
    	return h;
}

Node* outgoing(Graph* g, int* visited, int id)
{
	Node* t = g->graph[id].head;

	while (t != NULL)
    	{
        	if (visited[t->id] == 0)
                	return t;
        	t = t->next;
    	}
    	return NULL;
}

Heap* distance_update(Heap* h, int id, int d)
{
	int i;
	for (i = 0; i < h->n;i++)
    	{
        	if (h->heap[i].id == id)
        	{
            		h->heap[i].d = d;
           		break;
        	}
    	}
    	h = update(h); //heap update
    	return h;
}

Graph* Dijkstra(Graph* g, Heap* h)
{
	int src= g->n - 1;
	int v[g->n], i, del;

	h->heap[h->n - 1].d = 0;
	g->graph[h->heap[h->n - 1].id].d = 0;
	h = update(h);
    	
    	for (i = 1; i < g->n;i++)
		v[i] = 0;    
    	v[g->n - 1] = 1;
    	Node* n;

	for (i = 1; i < (g->n - 1);i++)
    	{
        	h = delete(h,&del);
        	v[del] = 1;

        	Node*t=g->graph[del].head;

        	while (t != NULL)
        	{
            		if ((g->graph[del].d + t->weight)<(g->graph[t->id].d))
            		{
                		g->graph[t->id].d = g->graph[del].d + t->weight;
                		h = distance_update(h, t->id, g->graph[t->id].d);
                		g->graph[t->id].prev = del;
            		}
            		t=t->next;
        	}
	}
    	return g;
}

Node* insert_path(Node* head, int id)
{
	Node* new = malloc(sizeof(Node));
    	new->id = id;
    	new->next = NULL;

    	if (head == NULL)
        	head=new;
    	else
    	{
        	Node* t = head;
        	while(t->next != NULL)
			t = t->next;        
        	t->next = new;
	}
    	return head;
}

int* reset(int* arr,int size)
{
	for (int i = 1; i < size; i ++)
		arr[i] = 0;    
	return arr;
}


void output(Graph* g)
{
	Paths* p = malloc(sizeof(Paths));
	p->paths = malloc((g->n - 1) * sizeof(Node));

	int src=g->n-1;
	int* arr = malloc(src * sizeof(int));
	int i;

    	for (i = 1; i < src; i ++)
    	{
        	if (g->graph[i].prev != 0)
        	{
            		Node* new = malloc(sizeof(Node));
            		new->id = i;
            		new->next = NULL;
            		p->paths[i].head = new; 
        	}
        	else
            		p->paths[i].head = NULL;
    	}

	for (i=1; i < src; i ++)
    	{
        	int prev= g->graph[i].prev;
		int j=0,k=0;
        	arr = reset(arr,src);

        	if (prev != 0)
        	{
            		while (prev != src)
            		{
                		arr[j] = prev;
                		j++;
                		prev =g->graph[prev].prev;
            		}
            		arr[j] = prev;
        	}
        	while (k <= j && (arr[j]==src))
        	{
            		p->paths[i].head = insert_path(p->paths[i].head,arr[k]);
            		k++;
		}
	}
	Node*t;

    	for (i = 1; i < src; i++)
    	{
        	t = p->paths[i].head;
        	if (t == NULL)
                	printf("%d NO PATH\n",i);
        	else
        	{
            		printf("%d ",i);

			while (t != NULL)
            		{
                		printf("%d ",t->id);
                		t = t->next;
            		}
            		printf("%d\n",g->graph[i].d);
        	}
    	}
}