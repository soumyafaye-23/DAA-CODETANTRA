/**
 * @file 1.1.9. Breadth First Search (BFS).c
 * @brief 1.1.9. Breadth First Search (BFS)
 * @strategy Graph Traversal
 * @complexity
 *   - Time Complexity:
 *     - Best: O(V + E), Avg: O(V + E), Worst: O(V + E)
 *   - Space Complexity: O(V)
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct node {
    int vertex;
    struct node *next;
};
typedef struct node *GNODE;

GNODE graph[MAX];
int visited[MAX];
int queue[MAX];
int front = 0, rear = 0;
int n;

int isEmptyQueue() {
    return (front == rear);
}

void insertQueue(int vertex) {
    queue[rear++] = vertex;
}

int deleteQueue() {
    if (isEmptyQueue()) {
        printf("Queue Underflow\n");
        exit(1);
    }
    return queue[front++];
}

void BFS(int v) {
    struct node *p;
    printf("\n");

    visited[v] = 1;
    insertQueue(v);

    while (!isEmptyQueue()) {
        v = deleteQueue();
        printf("%d\n", v);

        p = graph[v];
        while (p != NULL) {
            if (visited[p->vertex] == 0) {
                visited[p->vertex] = 1;
                insertQueue(p->vertex);
            }
            p = p->next;
        }
    }
}

int main() {
    int N, E, s, d, i, v;
    GNODE p, q;

    printf("Enter the number of vertices: ");
    if (scanf("%d", &N) != 1) return 0;
    n = N;

    for (i = 0; i < N; i++) {
        graph[i] = NULL;
        visited[i] = 0;
    }

    printf("Enter the number of edges: ");
    if (scanf("%d", &E) != 1) return 0;
    for (i = 1; i <= E; i++) {
        printf("Enter source: ");
        scanf("%d", &s);
        printf("Enter destination: ");
        scanf("%d", &d);

        q = (GNODE)malloc(sizeof(struct node));
        q->vertex = d;
        q->next = NULL;

        if (graph[s] == NULL) {
            graph[s] = q;
        } else {
            p = graph[s];
            while (p->next != NULL)
                p = p->next;
            p->next = q;
        }
    }

    printf("Enter Start Vertex for BFS: ");
    scanf("%d", &v);
    printf("BFS of graph: ");
    BFS(v);
    printf("\n");

    return 0;
}
