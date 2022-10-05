#include <stdio.h>
#include <stdlib.h>

struct adj_list_node
{
        int dest;
        struct adj_list_node *next;
};

struct adj_list
{
        struct adj_list_node *head;
};

struct Graph
{
        int V;
        struct adj_list *array;
};

struct adj_list_node* new_adj_list_node (int);
struct Graph* create_graph (int);
void add_edge (struct Graph *, int, int);
void print_graph (struct Graph *);

int
main (int argc, char *argv[])
{
        int V = 5;
        struct Graph* graph = create_graph (V);
        add_edge (graph, 0, 1);
        add_edge (graph, 0, 4);
        add_edge (graph, 1, 2);
        add_edge (graph, 1, 3);
        add_edge (graph, 1, 4);
        add_edge (graph, 2, 3);
        add_edge (graph, 3, 4);
     
        // print the adjacency list representation of the above
        // graph
        print_graph (graph);
        return 0;
}

struct adj_list_node*
new_adj_list_node (int dest)
{
        struct adj_list_node *new_node = (struct adj_list_node *) malloc (sizeof (struct adj_list_node));
        new_node->dest = dest;
        new_node->next = NULL;

        return new_node;
}

struct Graph*
create_graph (int V)
{
        struct Graph *graph = (struct Graph *) malloc (sizeof (struct Graph));
        graph->V = V;
        graph->array = (struct adj_list *) malloc (sizeof (struct adj_list) * V);

        int i;
        for (i = 0; i < V; i++)
                graph->array[i].head = NULL;

        return graph;
}

void
add_edge (struct Graph *graph, int src, int dest)
{
        struct adj_list_node *check = NULL;
        struct adj_list_node *new_node = new_adj_list_node (dest);
        if (graph->array[src].head == NULL) {
                new_node->next = graph->array[src].head;
                graph->array[src].head = new_node;
        } else {
                check = graph->array[src].head;
                while (check->next != NULL) {
                        check = check->next;
                }
                check->next = new_node;
        }

        new_node = new_adj_list_node (src);
        if (graph->array[dest].head == NULL) {
                new_node->next = graph->array[dest].head;
                graph->array[dest].head = new_node;
        } else {
                check = graph->array[dest].head;
                while (check->next != NULL) {
                        check = check->next;
                }
                check->next = new_node;
        }
}

void
print_graph (struct Graph *graph)
{
        int v;
	for (v = 0; v < graph->V; ++v) {
		struct adj_list_node* pCrawl = graph->array[v].head;
		printf("\n Adjacency list of vertex %d\n head ", v);
		while (pCrawl) {
			printf("-> %d", pCrawl->dest);
			pCrawl = pCrawl->next;
		}
		printf("\n");
	}
}
