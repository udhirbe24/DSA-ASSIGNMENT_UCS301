#include <iostream>
#include <vector>
using namespace std;
class Graph {
 int V; // number of verƟces
 bool directed; // directed or not
 vector<vector<int>> adjMat; // adjacency matrix
 vector<vector<int>> adjList; // adjacency list
public:
 // Constructor
 Graph(int verƟces, bool isDirected = false) {
 V = verƟces;
 directed = isDirected;
 // IniƟalize matrix with 0s
 adjMat.assign(V, vector<int>(V, 0));
 // IniƟalize adjacency list
 adjList.assign(V, vector<int>());
 }
 // Add edge
 void addEdge(int u, int v) {
 adjMat[u][v] = 1;
 adjList[u].push_back(v);
 if (!directed) {
 adjMat[v][u] = 1;
 adjList[v].push_back(u);
 }
 }

 // Display adjacency matrix
 void displayMatrix() {
 cout << "\nAdjacency Matrix:\n";
 for (int i = 0; i < V; i++) {
 for (int j = 0; j < V; j++)
 cout << adjMat[i][j] << " ";
 cout << endl;
 }
 }
 // Display adjacency list
 void displayList() {
 cout << "\nAdjacency List:\n";
 for (int i = 0; i < V; i++) {
 cout << i << " -> ";
 for (int v : adjList[i])
 cout << v << " ";
 cout << endl;
 }
 }
 // Degree (for undirected graph)
 int degree(int u) {
 return adjList[u].size();
 }
 // Out-degree (directed)
 int outDegree(int u) {
 return adjList[u].size();
 }

 // In-degree (directed)
 int inDegree(int u) {
 int count = 0;
 for (int i = 0; i < V; i++)
 if (adjMat[i][u] == 1)
 count++;
 return count;
 }
 // Adjacent verƟces
 void adjacentVerƟces(int u) {
 cout << "Adjacent verƟces of " << u << ": ";
 for (int v : adjList[u])
 cout << v << " ";
 cout << endl;
 }
 // Count edges
 int numberOfEdges() {
 int count = 0;
 for (int i = 0; i < V; i++)
 for (int j = 0; j < V; j++)
 if (adjMat[i][j] == 1)
 count++;
 return directed ? count : count / 2;
 }
};
int main() {
 int verƟces, edges, u, v;
 bool isDirected;

 cout << "Enter number of verƟces: ";
 cin >> verƟces;
 cout << "Directed graph? (1 for Yes, 0 for No): ";
 cin >> isDirected;
 Graph g(verƟces, isDirected);
 cout << "Enter number of edges: ";
 cin >> edges;
 cout << "Enter edges (u v):\n";
 for (int i = 0; i < edges; i++) {
 cin >> u >> v;
 g.addEdge(u, v);
 }
 g.displayMatrix();
 g.displayList();
 cout << "\nEnter a vertex to find degree/adjacent verƟces: ";
 cin >> u;
 if (!isDirected)
 cout << "Degree of " << u << " = " << g.degree(u) << endl;
 else {
 cout << "In-degree of " << u << " = " << g.inDegree(u) << endl;
 cout << "Out-degree of " << u << " = " << g.outDegree(u) << endl;
 }
 g.adjacentVerƟces(u);
 cout << "Total number of edges = " << g.numberOfEdges() << endl;
 return 0;
} 