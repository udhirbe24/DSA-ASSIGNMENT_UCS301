#include <iostream>
#include <vector>
using namespace std;
class Graph {
 int V;
 vector<vector<int>> adj;
public:
 Graph(int V) {
 this->V = V;
 adj.assign(V, vector<int>());
 }
 void addEdge(int u, int v) {
 adj[u].push_back(v);
 adj[v].push_back(u); // Undirected graph
 }
 void DFSUƟl(int node, vector<bool> &visited) {
 visited[node] = true;
 cout << node << " ";
 for (int neighbour : adj[node]) {
 if (!visited[neighbour]) {
 DFSUƟl(neighbour, visited);
 }
 }
 }
 void DFS(int start) {
 vector<bool> visited(V, false);
 cout << "DFS Traversal: ";
 DFSUƟl(start, visited);

 cout << endl;
 }
};
int main() {
 int V, E, u, v, start;
 cout << "Enter number of verƟces: ";
 cin >> V;
 Graph g(V);
 cout << "Enter number of edges: ";
 cin >> E;
 cout << "Enter edges (u v):\n";
 for (int i = 0; i < E; i++) {
 cin >> u >> v;
 g.addEdge(u, v);
 }
 cout << "Enter starƟng vertex for DFS: ";
 cin >> start;
 g.DFS(start);
 return 0;
}