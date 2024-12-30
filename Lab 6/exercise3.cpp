// Phạm Thị Minh Hiền
// 22520422

#include <iostream>
using namespace std;

const int MAX_VERTICES = 10; // Maximum number of vertices

class Graph {
private:
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

    // Recursive Depth-First Search
    void dfsRecursive(int start, bool visited[]) {
        if (visited[start]) return;

        cout << start << " ";
        visited[start] = true;

        Node* temp = adjacencyList[start];
        while (temp != nullptr) {
            dfsRecursive(temp->vertex, visited);
            temp = temp->next;
        }
    }

    // Iterative Depth-First Search
    void dfsIterative(int start) {
        bool visited[MAX_VERTICES] = {false};
        int stack[MAX_VERTICES];
        int top = -1;

        stack[++top] = start;

        while (top >= 0) {
            int current = stack[top--];

            if (!visited[current]) {
                cout << current << " ";
                visited[current] = true;

                // Push neighbors onto the stack
                Node* temp = adjacencyList[current];
                while (temp != nullptr) {
                    stack[++top] = temp->vertex;
                    temp = temp->next;
                }
            }
        }
    }

    // Breadth-First Search
    void bfs(int start) {
        bool visited[MAX_VERTICES] = {false};
        int queue[MAX_VERTICES];
        int front = 0, rear = 0;

        queue[rear++] = start;
        visited[start] = true;

        while (front < rear) {
            int current = queue[front++];

            cout << current << " ";

            // Enqueue neighbors
            Node* temp = adjacencyList[current];
            while (temp != nullptr) {
                if (!visited[temp->vertex]) {
                    queue[rear++] = temp->vertex;
                    visited[temp->vertex] = true;
                }
                temp = temp->next;
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

    // Adding edges
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 2);
    graph.addEdge(2, 0);
    graph.addEdge(2, 3);
    graph.addEdge(3, 3);

    // Display the adjacency list and matrix
    graph.displayAdjacencyList();
    graph.displayAdjacencyMatrix();

    // Perform DFS
    cout << "\nDFS Recursive starting from vertex 2:" << endl;
    bool visited[MAX_VERTICES] = {false};
    graph.dfsRecursive(2, visited);

    cout << "\nDFS Iterative starting from vertex 2:" << endl;
    graph.dfsIterative(2);

    // Perform BFS
    cout << "\nBFS starting from vertex 2:" << endl;
    graph.bfs(2);

    return 0;
}
