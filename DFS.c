#include<stdio.h>

int adj[20][20], visited[20], n, i, j;

void dfs(int v) {
    visited[v] = 1;
    for (i = 0; i < n; i++) {
        if (adj[v][i] && !visited[i]) {
            printf("\n%d -> %d", v, i);
            dfs(i);
        }
    }
}

int main() {
    int v;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &v);

    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }
    dfs(v);

    printf("\nVisited vertices: ");
    for (i = 0; i < n; i++) {
        if (visited[i]) {
            printf("%d ", i);
        }
    }
    for (i = 0; i < n; i++) {
        if (!visited[i]) {
            printf("\nDFS not possible for vertex %d", i);
        }
    }

    return 0;
}
