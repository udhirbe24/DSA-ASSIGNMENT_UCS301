#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Edge {
public:
 int src, dest, weight;
};
class Graph {
public:
 int V, E;
 vector<Edge> edges;
 Graph(int V, int E) {
 this->V = V;
 this->E = E;
 edges.resize(E);
 }
 // Find parent (for union-find)
 int findParent(int v, vector<int> &parent) {
 if (parent[v] == v)
 return v;
 return parent[v] = findParent(parent[v], parent); // path compression
 }
 // Union of two sets
 void doUnion(int u, int v, vector<int> &parent, vector<int> &rank) {
 u = findParent(u, parent);
 v = findParent(v, parent);

 if (rank[u] < rank[v])
 parent[u] = v;
 else if (rank[u] > rank[v])
 parent[v] = u;
 else {
 parent[v] = u;
 rank[u]++;
 }
 }
 // Kruskal Algorithm
 void kruskalMST() {
 vector<Edge> result;
 result.reserve(V - 1);
 // SorƟng edges by weight
 sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
 return a.weight < b.weight;
 });
 vector<int> parent(V);
 vector<int> rank(V, 0);
 for (int i = 0; i < V; i++)
 parent[i] = i;
 int edgeCount = 0;
 for (int i = 0; i < E && edgeCount < V - 1; i++) {
 Edge e = edges[i];
 int p1 = findParent(e.src, parent);
 int p2 = findParent(e.dest, parent);
 if (p1 != p2) {
 result.push_back(e);

 doUnion(p1, p2, parent, rank);
 edgeCount++;
 }
 }
 cout << "\nEdges in Minimum Spanning Tree:\n";
 int totalCost = 0;
 for (auto &e : result) {
 cout << e.src << " -- " << e.dest << " == " << e.weight << endl;
 totalCost += e.weight;
 }
 cout << "Total Weight of MST = " << totalCost << endl;
 }
};
int main() {
 int V, E;
 cout << "Enter number of verƟces: ";
 cin >> V;
 cout << "Enter number of edges: ";
 cin >> E;
 Graph g(V, E);
 cout << "Enter edges in format: src dest weight\n";
 for (int i = 0; i < E; i++) {
 cin >> g.edges[i].src >> g.edges[i].dest >> g.edges[i].weight;
 }
 g.kruskalMST();
 return 0;
}
