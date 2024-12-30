// Phạm Thị Minh Hiền
// 22520422

#include <iostream>
using namespace std;

class Graph {
private:
    static const int MAX_VERTICES = 10; // Maximum number of vertices
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES]; // Adjacency matrix
    struct Node {
        int vertex;
        Node* next;
    };
    Node* adjacencyList[MAX_VERTICES]; // Adjacency list as an array of linked lists
    int vertexCount;

public:
    // Constructor
    Graph() : vertexCount(0) {
        // Initialize adjacency matrix and adjacency list
        for (int i = 0; i < MAX_VERTICES; i++) {
            for (int j = 0; j < MAX_VERTICES; j++) {
                adjacencyMatrix[i][j] = 0;
            }
            adjacencyList[i] = nullptr;
        }
    }

    // Method to add a vertex
    void addVertex() {
        if (vertexCount >= MAX_VERTICES) {
            cout << "Maximum vertex limit reached." << endl;
            return;
        }
        vertexCount++;
    }

    // Method to add an edge
    void addEdge(int from, int to) {
        if (from >= vertexCount || to >= vertexCount) {
            cout << "Invalid vertices: " << from << " -> " << to << endl;
            return;
        }

        // Add edge to adjacency matrix
        adjacencyMatrix[from][to] = 1;

        // Add edge to adjacency list
        Node* newNode = new Node{to, adjacencyList[from]};
        adjacencyList[from] = newNode;
    }

    // Display the adjacency list
    void displayAdjacencyList() {
        cout << "Adjacency List:" << endl;
        for (int i = 0; i < vertexCount; i++) {
            cout << i << ": ";
            Node* temp = adjacencyList[i];
            while (temp != nullptr) {
                cout << temp->vertex << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    // Display the adjacency matrix
    void displayAdjacencyMatrix() {
        cout << "Adjacency Matrix:" << endl;
        for (int i = 0; i < vertexCount; i++) {
            for (int j = 0; j < vertexCount; j++) {
                cout << adjacencyMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Detect cycle in directed graph using DFS
    bool hasCycleDirectedUtil(int node, bool visited[], bool recStack[]) {
        if (!visited[node]) {
            visited[node] = true;
            recStack[node] = true;

            Node* temp = adjacencyList[node];
            while (temp != nullptr) {
                if (!visited[temp->vertex] && hasCycleDirectedUtil(temp->vertex, visited, recStack)) {
                    return true;
                } else if (recStack[temp->vertex]) {
                    return true;
                }
                temp = temp->next;
            }
        }
        recStack[node] = false;
        return false;
    }

    bool hasCycleDirected() {
        bool visited[MAX_VERTICES] = {false};
        bool recStack[MAX_VERTICES] = {false};

        for (int i = 0; i < vertexCount; i++) {
            if (!visited[i] && hasCycleDirectedUtil(i, visited, recStack)) {
                return true;
            }
        }
        return false;
    }

    // Detect cycle in undirected graph using DFS
    bool hasCycleUndirectedUtil(int node, int parent, bool visited[]) {
        visited[node] = true;

        Node* temp = adjacencyList[node];
        while (temp != nullptr) {
            if (!visited[temp->vertex]) {
                if (hasCycleUndirectedUtil(temp->vertex, node, visited)) {
                    return true;
                }
            } else if (temp->vertex != parent) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    bool hasCycleUndirected() {
        bool visited[MAX_VERTICES] = {false};

        for (int i = 0; i < vertexCount; i++) {
            if (!visited[i] && hasCycleUndirectedUtil(i, -1, visited)) {
                return true;
            }
        }
        return false;
    }

    // Destructor to clean up memory
    ~Graph() {
        for (int i = 0; i < vertexCount; i++) {
            Node* temp = adjacencyList[i];
            while (temp != nullptr) {
                Node* next = temp->next;
                delete temp;
                temp = next;
            }
        }
    }
};

int main() {
    Graph graph;

    // Adding vertices
    graph.addVertex(); // Vertex 0
    graph.addVertex(); // Vertex 1
    graph.addVertex(); // Vertex 2
    graph.addVertex(); // Vertex 3

    // Adding edges for directed graph
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 0);
    graph.addEdge(2, 3);

    // Display the adjacency list and matrix
    graph.displayAdjacencyList();
    graph.displayAdjacencyMatrix();

    // Check for cycles in directed graph
    cout << "\nChecking for cycles in directed graph: "
         << (graph.hasCycleDirected() ? "Cycle detected" : "No cycle detected") << endl;

    // Create a new graph for undirected testing
    Graph undirectedGraph;

    // Adding vertices
    undirectedGraph.addVertex(); // Vertex 0
    undirectedGraph.addVertex(); // Vertex 1
    undirectedGraph.addVertex(); // Vertex 2
    undirectedGraph.addVertex(); // Vertex 3

    // Adding edges for undirected graph
    undirectedGraph.addEdge(0, 1);
    undirectedGraph.addEdge(1, 2);
    undirectedGraph.addEdge(2, 0);
    undirectedGraph.addEdge(2, 3);

    // Check for cycles in undirected graph
    cout << "Checking for cycles in undirected graph: "
         << (undirectedGraph.hasCycleUndirected() ? "Cycle detected" : "No cycle detected") << endl;

    return 0;
}

       
