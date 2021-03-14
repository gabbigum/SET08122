#include <stdio.h>

#define NUM_VERTICES 6

struct Graph {
    struct Node* vertices[NUM_VERTICES];
};

struct Node {
    int target;
    struct Node *next;
};

struct Edge {
    int source;
    int target;
};


struct Graph* createGraph(struct Edge edges[], int numEdges) {
    struct Graph *graph = (struct Graph*) malloc(sizeof(struct Graph));
    
    for(int i = 0; i < NUM_VERTICES; i++) {
        graph->vertices[i] = NULL;
    }

    for(int i = 0; i < numEdges; i++) {
        int source = edges[i].source;
        int target = edges[i].target;

        struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
        newNode->target = target;
        newNode->next = graph->vertices[source];
        graph->vertices[source] = newNode;
    }
    return graph;
}

void printGraph(struct Graph* graph) {
    for(int i = 0; i < NUM_VERTICES; i++) {
        struct Node* iterator = graph->vertices[i];
        while(iterator != NULL) {
            printf("%d\n", iterator->target);
            iterator = iterator->next;
        }
    }
}

int main(int argc, char const *argv[])
{
    struct Edge edges[] = {
        {0,1}, {1,2}, {2,0}, {2,1}, {3, 2}, {4, 5}, {5, 4}
    };

    int n = sizeof(edges)/sizeof(edges[0]);
    struct Graph *graph = createGraph(edges, n);

    printGraph(graph);
    return 0;
}
