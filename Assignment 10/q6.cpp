#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
int minDistance(vector<int> &dist, vector<bool> &visited, int V) {
 int minVal = INT_MAX, minIndex = -1;

 for (int i = 0; i < V; i++) {
 if (!visited[i] && dist[i] <= minVal) {
 minVal = dist[i];
 minIndex = i;
 }
 }
 return minIndex;
}
void dijkstra(vector<vector<int>> &graph, int src, int V) {
 vector<int> dist(V, INT_MAX);
 vector<bool> visited(V, false);
 dist[src] = 0;
 for (int count = 0; count < V - 1; count++) {
 int u = minDistance(dist, visited, V);
 visited[u] = true;
 for (int v = 0; v < V; v++) {
 if (!visited[v] && graph[u][v] &&
 dist[u] != INT_MAX &&
 dist[u] + graph[u][v] < dist[v])
 {
 dist[v] = dist[u] + graph[u][v];
 }
 }
 }
 // Output
 cout << "\nShortest distances from source " << src << ":\n";
 for (int i = 0; i < V; i++) {
 cout << "Vertex " << i << " -> Distance = " << dist[i] << endl;

 }
}
int main() {
 int V, src;
 cout << "Enter number of verƟces: ";
 cin >> V;
 vector<vector<int>> graph(V, vector<int>(V));
 cout << "Enter adjacency matrix (0 for no edge):\n";
 for (int i = 0; i < V; i++)
 for (int j = 0; j < V; j++)
 cin >> graph[i][j];
 cout << "Enter source vertex: ";
 cin >> src;
 dijkstra(graph, src, V);
 return 0;
}