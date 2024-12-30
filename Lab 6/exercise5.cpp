// Phạm Thị Minh Hiền
// 22520422

#include <iostream>
using namespace std;

class Graph {
private:
    static const int MAX_VERTICES = 10; // Maximum number of vertices
    static const int INF = 1e9;         // Large value to represent infinity
    struct Node {
        int vertex;
        int weight;
        Node* next;
    };
    Node* adjacencyList[MAX_VERTICES]; // Adjacency list as an array of linked lists
    int vertexCount;

public:
    // Constructor
    Graph() : vertexCount(0) {
        for (int i = 0; i < MAX_VERTICES; i++) {
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

    // Method to add an edge with weight
    void addEdge(int from, int to, int weight) {
        if (from >= vertexCount || to >= vertexCount) {
            cout << "Invalid vertices: " << from << " -> " << to << endl;
            return;
        }

        // Add edge to adjacency list
        Node* newNode = new Node{to, weight, adjacencyList[from]};
        adjacencyList[from] = newNode;
    }

    // Display the adjacency list
    void displayAdjacencyList() {
        cout << "Adjacency List:" << endl;
        for (int i = 0; i < vertexCount; i++) {
            cout << i << ": ";
            Node* temp = adjacencyList[i];
            while (temp != nullptr) {
                cout << "(" << temp->vertex << ", " << temp->weight << ") ";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    // Dijkstra's algorithm to find shortest paths
    void dijkstra(int source) {
        int distances[MAX_VERTICES];
        bool visited[MAX_VERTICES] = {false};

        // Initialize distances
        for (int i = 0; i < vertexCount; i++) {
            distances[i] = INF;
        }
        distances[source] = 0;

        for (int count = 0; count < vertexCount - 1; count++) {
            // Find the vertex with the minimum distance
            int minDistance = INF, minIndex = -1;
            for (int i = 0; i < vertexCount; i++) {
                if (!visited[i] && distances[i] < minDistance) {
                    minDistance = distances[i];
                    minIndex = i;
                }
            }

            if (minIndex == -1) break; // All reachable vertices are processed

            // Mark the selected vertex as visited
            visited[minIndex] = true;

            // Update distances of adjacent vertices
            Node* temp = adjacencyList[minIndex];
            while (temp != nullptr) {
                int neighbor = temp->vertex;
                int weight = temp->weight;

                if (!visited[neighbor] && distances[minIndex] != INF &&
                    distances[minIndex] + weight < distances[neighbor]) {
                    distances[neighbor] = distances[minIndex] + weight;
                }

                temp = temp->next;
            }
        }

        // Print the shortest paths
        cout << "\nShortest paths from vertex " << source << ":" << endl;
        for (int i = 0; i < vertexCount; i++) {
            cout << "Vertex " << i << " : ";
            if (distances[i] == INF) {
                cout << "INF" << endl;
            } else {
                cout << distances[i] << endl;
            }
        }
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

    // Adding edges with weights
    graph.addEdge(0, 1, 1);
    graph.addEdge(0, 2, 4);
    graph.addEdge(1, 2, 2);
    graph.addEdge(1, 3, 6);
    graph.addEdge(2, 3, 3);

    // Display the adjacency list
    graph.displayAdjacencyList();

    // Perform Dijkstra's algorithm from source vertex 0
    graph.dijkstra(0);

    return 0;
}
