#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

struct node{
    int vertex;
    struct node* next;
    struct node* prev;
};
typedef struct node node;

struct Graph{
    int num_vertices;
    node** adj_lists;
    node** rear;
};
typedef struct Graph Graph;

node* create_node(int);
Graph* create_a_graph(int);
void add_edge(Graph*, int, int);
void print_graph(Graph*, FILE*);
void bfs(Graph*, int, int, FILE*);
void dfs(Graph*, int, int, FILE*);
void delete_vertex(Graph*, int);
int check_cover(Graph*, FILE*);


#endif // GRAPH_H_INCLUDED
