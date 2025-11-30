#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
int minKey(vector<int> &key, vector<bool> &mstSet, int V) {
 int minValue = INT_MAX, minIndex;
 for (int v = 0; v < V; v++) {
 if (!mstSet[v] && key[v] < minValue) {
 minValue = key[v];
 minIndex = v;
 }
 }
 return minIndex;
}
void primMST(vector<vector<int>> &graph, int V) {
 vector<int> parent(V); // Store MST

 vector<int> key(V, INT_MAX);
 vector<bool> mstSet(V, false);
 key[0] = 0; // Start from vertex 0
 parent[0] = -1; // Root has no parent
 for (int count = 0; count < V - 1; count++) {
 int u = minKey(key, mstSet, V);
 mstSet[u] = true;
 for (int v = 0; v < V; v++) {
 if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
 parent[v] = u;
 key[v] = graph[u][v];
 }
 }
 }
 cout << "\nEdges in Minimum Spanning Tree:\n";
 int totalCost = 0;
 for (int i = 1; i < V; i++) {
 cout << parent[i] << " -- " << i << " == " << graph[i][parent[i]] << endl;
 totalCost += graph[i][parent[i]];
 }
 cout << "Total Weight of MST = " << totalCost << endl;
}
int main() {
 int V;
 cout << "Enter number of verƟces: ";
 cin >> V;
 vector<vector<int>> graph(V, vector<int>(V));

 cout << "Enter adjacency matrix (0 for no edge):\n";
 for (int i = 0; i < V; i++)
 for (int j = 0; j < V; j++)
 cin >> graph[i][j];
 primMST(graph, V);
 return 0;
}
