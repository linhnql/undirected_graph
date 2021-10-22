#include <stdio.h>
#include "graph.h"
#include "queue.h"
#include "stack.h"

node* create_node(int v){
    node *new_node = malloc(sizeof(node));
    new_node -> vertex = v;
    new_node -> next = NULL;
    new_node -> prev = NULL;
    return new_node;
}

Graph* create_a_graph(int vertices){
    Graph* graph = malloc(sizeof(Graph));
    graph -> num_vertices = vertices;
    graph -> head = malloc(vertices * sizeof(node*));
    graph -> rear = malloc(vertices * sizeof(node*));
    for (int i = 0; i < vertices; ++i){
        graph -> head[i] = NULL;
        graph -> rear[i] = NULL;
    }
    return graph;
};

void add_edge(Graph* graph, int s, int d){
    // Add edge from s to d
    node* new_node = create_node(d);
    if (graph -> head[s] == NULL) graph -> head[s] = new_node, graph -> rear[s] = new_node;
    else {
        new_node -> prev = graph -> rear[s];
        graph -> rear[s] -> next = new_node;
        graph -> rear[s] = new_node;
    }
}

void build_graph(Graph* graph, FILE* f){
    skip_line(f); skip_line(f); skip_line(f); skip_line(f);
    int s, d;
    while (fscanf(f, "%d", &s) == 1, fscanf(f, "%d", &d) == 1){
        add_edge(graph, s, d);
    }
    fclose(f);
}

void print_graph(Graph* graph, FILE* f){
    for (int v = 0; v < graph -> num_vertices; ++v){
        node* temp = graph -> head[v];
        fprintf(f, "\nV%d: ", v);
        while (temp){
            fprintf(f, "%d ", temp -> vertex);
            temp = temp -> next;
        }
    }
}

void bfs(Graph* graph, int start_vertex, int num_vertices, FILE* f){
    int* visited;
    visited = (int*)calloc(num_vertices, sizeof(int));
    queue *q = create_queue();

    visited[start_vertex] = 1;
    enqueue(q, start_vertex);
    while (!q_empty(q)) {
        int curVer = dequeue(q);
        fprintf(f, "%d ", curVer);

        node* temp = graph -> head[curVer];
        while (temp){
            int adjVer = temp -> vertex;
            if (visited[adjVer] == 0) visited[adjVer] = 1, enqueue(q, adjVer);
            temp = temp -> next;
        }
    }
    free(visited); fclose(f);
}

void dfs(Graph* graph, int start_vertex, int num_vertices, FILE* f){
    int* visited;
    visited = (int*)calloc(num_vertices, sizeof(int));
    creat();

    push(start_vertex);
    while (st_empty() == 0){
        int curVer = pTop -> data;
        pop();
        if (visited[curVer] == 0){
            fprintf(f, "%d ", curVer);
            visited[curVer] = 1;
        }

        node* temp = graph -> rear[curVer];
        while (temp){
            int adjVer = temp -> vertex;
            if (visited[adjVer] == 0) push(adjVer);
            temp = temp -> prev;
        }
    }
    free(visited); close(f);
}

void delete_vertex(Graph* graph, int v){
    node* temp = graph -> head[v];
    while (temp){
        int cur_ver = temp -> vertex;

        node* sub_ver = graph -> head[cur_ver];
        if (sub_ver -> vertex == v){
            if (sub_ver -> next){
                graph -> head[cur_ver] -> vertex = sub_ver -> next -> vertex;
                graph -> head[cur_ver] = sub_ver -> next;
                free(sub_ver);
            } else {
                graph -> head[cur_ver] = NULL;
                free(sub_ver);
            }
            temp = temp -> next;
            continue;
        }

        while (sub_ver -> next){
            node* next_sub_ver = sub_ver -> next;
            if (sub_ver -> next -> next){
                if (next_sub_ver -> vertex == v){
                    sub_ver -> next -> vertex = next_sub_ver -> next -> vertex;
                    sub_ver -> next = next_sub_ver -> next;
                    free(next_sub_ver);
                    break;
                }
            } else {
                if (next_sub_ver -> vertex == v){
                    sub_ver -> next = NULL;
                    free(next_sub_ver);
                    break;
                }
            }
            sub_ver = sub_ver -> next;
        }
        temp = temp -> next;
    }
    graph -> adj_lists[v] = NULL;
}

int check_cover(Graph* graph, FILE* f){
    skip_line(f); skip_line(f); skip_line(f);
    char c; int v;
    while((c = getc(f)) != EOF){
        if(c == 'v') continue;
        else{
            fscanf(f, "%d", &v);
            delete_vertex(graph, v);
            c = getc(f);
        }
    }
    fclose(f);

    for (int v = 0; v < graph -> num_vertices; ++v){
        if (graph -> head[v] != NULL) return 0;
    }
    return 1;
}
