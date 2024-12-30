// Phạm Thị Minh Hiền
// 22520422

#include <iostream>
using namespace std;

class Graph {
private:
    static const int MAX_VERTICES = 10; // Maximum number of vertices
    static const int INF = 1e9;         // A large value to represent infinity
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

        // Add edge to adjacency list (undirected graph)
        Node* newNode = new Node{to, weight, adjacencyList[from]};
        adjacencyList[from] = newNode;

        newNode = new Node{from, weight, adjacencyList[to]};
        adjacencyList[to] = newNode;
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

        for (int count = 0; count < vertexCount; count++) {
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

    // Find all connected components using DFS
    void findConnectedComponents() {
        bool visited[MAX_VERTICES] = {false};
        int components[MAX_VERTICES][MAX_VERTICES];
        int componentCount = 0;

        for (int i = 0; i < vertexCount; i++) {
            if (!visited[i]) {
                int stack[MAX_VERTICES];
                int top = -1;
                stack[++top] = i;

                int componentSize = 0;
                while (top >= 0) {
                    int current = stack[top--];

                    if (!visited[current]) {
                        visited[current] = true;
                        components[componentCount][componentSize++] = current;

                        Node* temp = adjacencyList[current];
                        while (temp != nullptr) {
                            if (!visited[temp->vertex]) {
                                stack[++top] = temp->vertex;
                            }
                            temp = temp->next;
                        }
                    }
                }

                components[componentCount][componentSize] = -1; // Mark the end of the component
                componentCount++;
            }
        }

        // Print all connected components
        cout << "\nConnected Components:" << endl;
        for (int i = 0; i < componentCount; i++) {
            int j = 0;
            while (components[i][j] != -1) {
                cout << components[i][j] << " ";
                j++;
            }
            cout << endl;
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
    graph.addVertex(); // Vertex 4

    // Adding edges with weights
    graph.addEdge(0, 1, 1);
    graph.addEdge(1, 2, 1);
    graph.addEdge(3, 4, 1);

    // Display the adjacency list
    graph.displayAdjacencyList();

    // Perform Dijkstra's algorithm from source vertex 0
    graph.dijkstra(0);

    // Find all connected components
    graph.findConnectedComponents();

    return 0;
}
