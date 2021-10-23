#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "stack.h"
#include "graph.h"

int skip_line(FILE *f){
    int c;
    while (c = fgetc(f), c != '\n' && c != EOF);
    return c;
}

int main(){

    main_thread();

    return 0;
}

void main_menu(){
    printf("\n\t=========== MAIN MENU =============\n");
	printf("\t1. TEST\n");
	printf("\t2. Road network of California\n");
	printf("\t3. Road network of Pennsylvania\n");
	printf("\t4. Road network of Texas\n");
	printf("\tOr other button to exit!\n");
	printf("\t===================================\n");
}

void main_thread(){
    main_menu();
    while (1){
        printf("Select Menu: ");
        int sel; scanf("%d", &sel);
        switch (sel) {
        case 1:
            {
                char input_file[] = "C:\\test\\input.txt";
                FILE* bfs_file = fopen("C:\\test\\outputBFS.txt", "w");
                FILE* dfs_file = fopen("C:\\test\\outputDFS.txt", "w");
                FILE *ver_cover_file = fopen("C:\\test\\vertexCover.txt", "r");
                FILE* output_file = fopen("C:\\test\\output.txt", "w");

                sub_menu("TEST");
                sub_thread(input_file, bfs_file, dfs_file, ver_cover_file, output_file);
            }break;
        case 2:
            {
                char input_file[] = "C:\\roadNet-CA\\roadNet-CA.txt";
                FILE* bfs_file = fopen("C:\\roadNet-CA\\outputBFS.txt", "w");
                FILE* dfs_file = fopen("C:\\roadNet-CA\\outputDFS.txt", "w");
                FILE *ver_cover_file = fopen("C:\\roadNet-CA\\roadNet-CA.VC", "r");
                FILE* output_file = fopen("C:\\roadNet-CA\\output.txt", "w");

                sub_menu("CA");
                sub_thread(input_file, bfs_file, dfs_file, ver_cover_file, output_file);
            }break;
        case 3:
            {
                char input_file[] = "C:\\roadNet-PA\\roadNet-PA.txt";
                FILE* bfs_file = fopen("C:\\roadNet-PA\\outputBFS.txt", "w");
                FILE* dfs_file = fopen("C:\\roadNet-PA\\outputDFS.txt", "w");
                FILE *ver_cover_file = fopen("C:\\roadNet-PA\\roadNet-PA.VC", "r");
                FILE* output_file = fopen("C:\\roadNet-PA\\output.txt", "w");

                sub_menu("PA");
                sub_thread(input_file, bfs_file, dfs_file, ver_cover_file, output_file);

            }break;
        case 4:
            {
                char input_file[] = "C:\\roadNet-TX\\roadNet-TX.txt";
                FILE* bfs_file = fopen("C:\\roadNet-TX\\outputBFS.txt", "w");
                FILE* dfs_file = fopen("C:\\roadNet-TX\\outputDFS.txt", "w");
                FILE *ver_cover_file = fopen("C:\\roadNet-TX\\roadNet-TX.VC", "r");
                FILE* output_file = fopen("C:\\roadNet-TX\\output.txt", "w");

                sub_menu("TX");
                sub_thread(input_file, bfs_file, dfs_file, ver_cover_file, output_file);
            }break;
        default:
            printf("\tEXITTTT");
            exit(1);
            break;
        }
    }
}

void sub_menu(char choice[]) {
	printf("\n\t\t~~~~~~~~~~~~~ %s MENU ~~~~~~~~~~~~~\n", choice);
	printf("\t\t1. BFS\n");
	printf("\t\t2. DFS\n");
	printf("\t\t3. Check Vertex Cover\n");
	printf("\t\t4. Print Graph\n");
	printf("\t\tOr other button to back main menu!\n");
	printf("\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

void sub_thread(char input_file[], FILE* bfs_file, FILE* dfs_file, FILE* ver_cover_file, FILE* output_file){
    FILE *input_graph = fopen(input_file, "r");
    if (input_graph == NULL){
        perror("Unable to open the file");
        exit(1);
    }

    printf("Graph making process...");
    int num_vertex = count_vertices(input_file) + 1;
    Graph* graph = create_a_graph(num_vertex);
    build_graph(graph, input_graph);
    printf("\t\tProcessing is finished\n");

    while (1){
        printf("\n\tChoice: ");
        int n; scanf("%d", &n);

        switch (n){
        case 1:
            {
                bfs(graph, 2, num_vertex, bfs_file);
                printf("\t\tBFS Done!\n");
            }break;

        case 2:
            {
                dfs(graph, 2, num_vertex, dfs_file);
                printf("\t\tDFS Done!\n");
            }break;

        case 3:
            {
                if (ver_cover_file == NULL){
                    perror("Unable to open the file");
                    exit(1);
                }

                FILE *input_temp_graph = fopen(input_file, "r");
                Graph* temp_graph = create_a_graph(num_vertex);
                build_graph(temp_graph, input_temp_graph);

                if (check_cover(temp_graph, ver_cover_file))
                    printf("\t\tVertex Cover\n");
                else printf("\t\tNOOOOO Vertex Cover\n");

                free(temp_graph);
            }break;

        case 4:
            {
                print_graph(graph, output_file);
                printf("\t\tPrint Graph Done!\n");
            }break;

        default:
            printf("\t\tBack to main menu!!!\n");
            main_thread();
            break;
        }
    }
    free(graph);
}
