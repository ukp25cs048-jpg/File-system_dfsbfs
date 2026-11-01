#include <stdio.h>
#include <string.h>

#define MAX 20

int graph[MAX][MAX];
int visited[MAX];
char names[MAX][50];
int n;

// BFS traversal and search
int bfs(int start, char target[]) {
    int queue[MAX];
    int front = 0, rear = 0;
    int found = 0;

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    visited[start] = 1;
    queue[rear++] = start;

    printf("\nBFS Traversal: ");

    while (front < rear) {
        int current = queue[front++];

        printf("%s ", names[current]);

        if (strcmp(names[current], target) == 0)
            found = 1;

        for (int i = 0; i < n; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }

    return found;
}

// DFS traversal and search
int dfsUtil(int current, char target[]) {
    int found = 0;

    visited[current] = 1;
    printf("%s ", names[current]);

    if (strcmp(names[current], target) == 0)
        found = 1;

    for (int i = 0; i < n; i++) {
        if (graph[current][i] == 1 && !visited[i]) {
            if (dfsUtil(i, target))
                found = 1;
        }
    }

    return found;
}

int dfs(int start, char target[]) {
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    printf("\nDFS Traversal: ");

    return dfsUtil(start, target);
}

int main() {
    int start;
    char target[50];

    printf("FILE SYSTEM REPRESENTATION USING BFS AND DFS\n");

    printf("\nEnter number of files/directories: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX) {
        printf("Invalid number of nodes!\n");
        return 1;
    }

    printf("\nEnter names of files/directories:\n");
    for (int i = 0; i < n; i++) {
        printf("Node %d: ", i);
        scanf("%49s", names[i]);
    }

    printf("\nEnter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);

            if (graph[i][j] != 0 && graph[i][j] != 1) {
                printf("Invalid matrix value!\n");
                return 1;
            }
        }
    }

    printf("\nEnter starting node index (0 to %d): ", n - 1);
    scanf("%d", &start);

    if (start < 0 || start >= n) {
        printf("Invalid starting node!\n");
        return 1;
    }

    printf("Enter file/directory to search: ");
    scanf("%49s", target);

    int bfsResult = bfs(start, target);

    printf("\nBFS Search: ");
    if (bfsResult)
        printf("File Found!\n");
    else
        printf("File Not Found!\n");

    int dfsResult = dfs(start, target);

    printf("\nDFS Search: ");
    if (dfsResult)
        printf("File Found!\n");
    else
        printf("File Not Found!\n");

    return 0;
}
