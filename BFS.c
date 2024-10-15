#include<stdio.h>
int n, i, j, visited[10], queue[10];
int adj[10][10], front = -1, rear = -1;
void bfs(int v) {
 visited[v] = 1;
 queue[++rear] = v;
 while (front < rear) {
v = queue[++front];
for (i = 0; i < n; i++) {
if (adj[v][i] && !visited[i]) 
{
 queue[++rear] = i;
visited[i] = 1; 
}}}}
int main() {
int v;
printf("Enter the number of vertices: ");
scanf("%d", &n);
printf("Enter the adjacency matrix:\n");
for (i = 0; i < n; i++) {
for (j = 0; j < n; j++) {
scanf("%d", &adj[i][j]);
}}
printf("Enter the starting vertex: ");
scanf("%d", &v);
for (i = 0; i < n; i++) {
visited[i] = 0;
}
bfs(v);
printf("BFS traversal from vertex %d: ", v);
for (i = 0; i < n; i++) {
if (visited[i]) {
printf("%d ", i);
}
}
printf("\n");
return 0;
}
