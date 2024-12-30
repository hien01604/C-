// Phạm Thị Minh Hiền
// 22520422

#include <iostream>
using namespace std;

class Graph {
private:
    static const int MAX_VERTICES = 10; // Maximum number of vertices
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES]; // Adjacency matrix
    int vertexCount;
    struct Node {
        int vertex;
        Node* next;
    };
    Node* adjacencyList[MAX_VERTICES]; // Adjacency list as an array of linked lists

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

    // Adding edges
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 0);

    // Display the adjacency list and matrix
    graph.displayAdjacencyList();
    graph.displayAdjacencyMatrix();

    return 0;
}
