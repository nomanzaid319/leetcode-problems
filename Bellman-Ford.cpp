#include <iostream>

#include <vector>

using namespace std;


struct Edge

{

int u;

int v;

int weight;

};


void bellmanFord(int V, int source, vector<Edge>& edges)

{

const int INF = 99999;


vector<int> dist(V, INF);


dist[source] = 0;


// Relax all edges V-1 times

for (int i = 1; i <= V - 1; i++)

{

for (auto edge : edges)

{

int u = edge.u;

int v = edge.v;

int weight = edge.weight;


if (dist[u] != INF &&

dist[u] + weight < dist[v])

{

dist[v] = dist[u] + weight;

}

}

}

cout << "Shortest distances from source " << source << ":\n";


for (int i = 0; i < V; i++)

{

cout << source << " -> "

<< i << " = "

<< dist[i] << endl;

}

}


int main()

{

int V = 5;


vector<Edge> edges =

{

{0, 1, 6},

{0, 2, 7},

{1, 2, 8},

{1, 3, 5},

{1, 4, -4},

{2, 3, -3},

{2, 4, 9},

{3, 1, -2},

{4, 0, 2},

{4, 3, 7}

};


bellmanFord(V, 0, edges);

return 0;

}