#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "stack.h"
#include "graph.h"

void Menu();

int skip_line(FILE *f){
    int c;
    while (c = fgetc(f), c != '\n' && c != EOF);
    return c;
}

int count_vertices(char direc_file[]){
    FILE *f = fopen(direc_file, "r");
    skip_line(f);    skip_line(f);
    skip_line(f);    skip_line(f);

    int n; fscanf(f, "%d", &n);
    int max = n;
    while (fscanf(f, "%d", &n) == 1) max = n > max ? n : max;

    fclose(f);
    return max;
}

int main(){
    char direc_input_file[] = "C:\\Users\\DELL\\OneDrive\\Máy tính\\Project I\\Project I\\roadNet-PA\\roadNet-PA.txt";
    FILE *input_graph = fopen(direc_input_file, "r");
    if (input_graph == NULL){
        perror("Unable to open the file");
        exit(1);
    }
    // Build graph
    int num_vertex = count_vertices(direc_input_file) + 1;
    Graph* graph = create_a_graph(num_vertex);
    build_graph(graph, input_graph);

    Menu();
    while (1){
        printf("\n   Select Menu: ");
        int n; scanf("%d", &n);
        switch (n){
        // breath first search
        case 1:{
            FILE* bfs_file = fopen("C:\\Users\\DELL\\OneDrive\\Máy tính\\Project I\\Project I\\roadNet-PA\\outputBFS.txt", "w");
            bfs(graph, 2, num_vertex, bfs_file);
            printf("\tBFS Done!\n");
        }
            break;

        // deep first search
        case 2:{
            FILE* dfs_file = fopen("C:\\Users\\DELL\\OneDrive\\Máy tính\\Project I\\Project I\\roadNet-PA\\outputDFS.txt", "w");
            dfs(graph, 2, num_vertex, dfs_file);
            printf("\tDFS Done!\n");
        }
            break;

        // check vertex cover
        case 3:{
            FILE *ver_cover_file = fopen("C:\\Users\\DELL\\OneDrive\\Máy tính\\Project I\\Project I\\roadNet-PA\\roadNet-PA.VC", "r");
            if (ver_cover_file == NULL){                                                                  // vertexCover
                perror("Unable to open the file");
                exit(1);
            }

            FILE *input_temp_graph = fopen("C:\\Users\\DELL\\OneDrive\\Máy tính\\Project I\\Project I\\roadNet-PA\\roadNet-PA.txt", "r");
            Graph* temp_graph = create_a_graph(num_vertex);
            build_graph(temp_graph, input_temp_graph);

            if (check_cover(temp_graph, ver_cover_file))
                printf("\tVertex Cover\n");
            else printf("\tDon't Vertex Cover\n");
        }
            break;

        case 4:{
            // Print graph
            FILE* output_file = fopen("C:\\Users\\DELL\\OneDrive\\Máy tính\\Project I\\Project I\\roadNet-PA\\output.txt", "w");
            print_graph(graph, output_file);
            printf("\tPrint Graph\n");
        }
            break;

        default:
            printf("\tEXIT!!!\n");
            exit(1);

            break;
        }
    }

    return 0;
}

void Menu() {
	printf("\n\t=================MENU==============\n");
	printf("\t1. BFS\n");
	printf("\t2. DFS\n");
	printf("\t3. Check Vertex Cover\n");
	printf("\t4. Print Graph\n");
	printf("\tOr other button to exit!\n");
	printf("\t===================================\n");
}
