#include <stdio.h>
#include <stdlib.h>

struct node
{
        int vertex;
        struct node *next;
};

struct Graph
{
        int vertex_num;
        struct node **adj_lists;
};

struct node* create_node (int);
struct Graph* create_graph (int);
void add_edge (struct Graph *, int, int);
void print_graph (struct Graph *);

int
main (int argc, char *argv[])
{
        struct Graph* graph = create_graph(4);
        add_edge (graph, 0, 1);
        add_edge (graph, 0, 2);
        add_edge (graph, 0, 3);
        add_edge (graph, 1, 2);

        print_graph (graph);

        return 0;
}

struct node*
create_node (int v)
{
        struct node *new_node = (struct node *) malloc (sizeof (struct node));
        new_node->vertex = v;
        new_node->next = NULL;

        return new_node;
}

struct Graph*
create_graph (int vertex_num)
{
        struct Graph *new_graph = (struct Graph *) malloc (sizeof (struct Graph));
        new_graph->vertex_num = vertex_num;
        new_graph->adj_lists = (struct node **) calloc (vertex_num, sizeof (struct node));

        int i;
        for (i = 0; i < vertex_num; i++)
                new_graph->adj_lists[i] = NULL;

        return new_graph;
}

void
add_edge (struct Graph *graph,
                int s, int d)
{
        struct node *new_node = create_node (d);
        new_node->next = graph->adj_lists[s];
        graph->adj_lists[s] = new_node;

        new_node = create_node (s);
        new_node->next = graph->adj_lists[d];
        graph->adj_lists[d] = new_node;
}

void
print_graph (struct Graph *graph)
{
        int v;
        for (v = 0; v < graph->vertex_num; v++) {
                struct node* temp = graph->adj_lists[v];
                printf("\n Vertex %d\n: ", v);
                while (temp) {
                        printf("%d -> ", temp->vertex);
                        temp = temp->next;
                }
                printf("\n");
        }
}
