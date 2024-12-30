// Phạm Thị Minh Hiền
// 22520422

#include <iostream>
using namespace std;

class Graph {
    int V;                // Number of vertices
    int **adj;            // Adjacency matrix
    int time;             // Time counter for DFS
    int **bridges;        // To store bridges
    int bridgeCount;      // Number of bridges

    void bridgeUtil(int v, bool visited[], int disc[], int low[], int parent[]);

public:
    Graph(int V);
    ~Graph();
    void addEdge(int v, int w);
    void findBridges();
};

Graph::Graph(int V) {
    this->V = V;
    this->time = 0;
    this->bridgeCount = 0;

    // Allocate memory for adjacency matrix
    adj = new int *[V];
    for (int i = 0; i < V; i++) {
        adj[i] = new int[V];
        for (int j = 0; j < V; j++) {
            adj[i][j] = 0;
        }
    }

    // Allocate memory for storing bridges
    bridges = new int *[V];
    for (int i = 0; i < V; i++) {
        bridges[i] = new int[2]; // Each bridge has two endpoints
    }
}

Graph::~Graph() {
    for (int i = 0; i < V; i++) {
        delete[] adj[i];
    }
    delete[] adj;

    for (int i = 0; i < V; i++) {
        delete[] bridges[i];
    }
    delete[] bridges;
}

void Graph::addEdge(int v, int w) {
    adj[v][w] = 1;
    adj[w][v] = 1; // Since the graph is undirected
}

void Graph::bridgeUtil(int v, bool visited[], int disc[], int low[], int parent[]) {
    visited[v] = true;
    disc[v] = low[v] = ++time;

    for (int i = 0; i < V; i++) {
        if (adj[v][i] == 1) { // There is an edge between v and i
            if (!visited[i]) {
                parent[i] = v;
                bridgeUtil(i, visited, disc, low, parent);

                // Check if the subtree rooted at i has a connection back to one of the ancestors of v
                low[v] = (low[v] < low[i]) ? low[v] : low[i];

                // If the lowest vertex reachable from subtree under i is above v in DFS tree, it's a bridge
                if (low[i] > disc[v]) {
                    bridges[bridgeCount][0] = v;
                    bridges[bridgeCount][1] = i;
                    bridgeCount++;
                }
            } else if (i != parent[v]) {
                low[v] = (low[v] < disc[i]) ? low[v] : disc[i];
            }
        }
    }
}

void Graph::findBridges() {
    bool *visited = new bool[V];
    int *disc = new int[V];
    int *low = new int[V];
    int *parent = new int[V];

    for (int i = 0; i < V; i++) {
        visited[i] = false;
        parent[i] = -1;
        disc[i] = 0;
        low[i] = 0;
    }

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            bridgeUtil(i, visited, disc, low, parent);
        }
    }

    // Print bridges
    cout << "Bridges in the graph are:\n";
    for (int i = 0; i < bridgeCount; i++) {
        cout << bridges[i][0] << " -- " << bridges[i][1] << endl;
    }

    delete[] visited;
    delete[] disc;
    delete[] low;
    delete[] parent;
}

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(3, 4);

    cout << "Bridges in the graph are:\n";
    g.findBridges();

    return 0;
}
