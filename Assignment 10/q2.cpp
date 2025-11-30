#include <iostream>
#include <queue>
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
 adj[v].push_back(u); // for undirected graph

 }
 void BFS(int start) {
 vector<bool> visited(V, false);
 queue<int> q;
 visited[start] = true;
 q.push(start);
 cout << "BFS Traversal: ";
 while (!q.empty()) {
 int node = q.front();
 q.pop();
 cout << node << " ";
 for (int neighbour : adj[node]) {
 if (!visited[neighbour]) {
 visited[neighbour] = true;
 q.push(neighbour);
 }
 }
 }
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
 cout << "Enter starƟng vertex for BFS: ";
 cin >> start;
 g.BFS(start);
 return 0;
}
