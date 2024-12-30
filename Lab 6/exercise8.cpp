// Phạm Thị Minh Hiền
// 22520422

#include <iostream>
using namespace std;

class Graph {
private:
    static const int MAX_VERTICES = 10; // Maximum number of vertices
    int V;                              // Number of vertices
    struct Node {
        int vertex;
        double weight;
        Node* next;
    };
    Node* adjacencyList[MAX_VERTICES]; // Adjacency list as an array of linked lists

public:
    Graph(int V);
    ~Graph();
    void addEdge(int v, int w, double weight);
    void louvainMethod(int communities[]);
    double modularity(int communities[]);

private:
    void clearMemory();
};

Graph::Graph(int V) {
    this->V = V;
    for (int i = 0; i < MAX_VERTICES; ++i) {
        adjacencyList[i] = nullptr;
    }
}

Graph::~Graph() {
    clearMemory();
}

void Graph::addEdge(int v, int w, double weight) {
    Node* newNode = new Node{w, weight, adjacencyList[v]};
    adjacencyList[v] = newNode;

    // Add reverse edge since the graph is undirected
    newNode = new Node{v, weight, adjacencyList[w]};
    adjacencyList[w] = newNode;
}

void Graph::clearMemory() {
    for (int i = 0; i < V; ++i) {
        Node* current = adjacencyList[i];
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
}

void Graph::louvainMethod(int communities[]) {
    // Initialize each node in its own community
    for (int i = 0; i < V; ++i) {
        communities[i] = i;
    }

    bool improvement = true;
    while (improvement) {
        improvement = false;

        for (int i = 0; i < V; ++i) {
            double communityWeights[MAX_VERTICES] = {0.0};
            Node* current = adjacencyList[i];

            // Calculate weights to each community
            while (current != nullptr) {
                int neighbor = current->vertex;
                int community = communities[neighbor];
                communityWeights[community] += current->weight;
                current = current->next;
            }

            // Find the best community for the node
            int bestCommunity = communities[i];
            double bestIncrease = 0.0;
            for (int j = 0; j < V; ++j) {
                if (communityWeights[j] > bestIncrease) {
                    bestCommunity = j;
                    bestIncrease = communityWeights[j];
                }
            }

            if (bestCommunity != communities[i]) {
                communities[i] = bestCommunity;
                improvement = true;
            }
        }
    }
}

double Graph::modularity(int communities[]) {
    double mod = 0.0;
    double totalWeight = 0.0;
    double communityWeights[MAX_VERTICES] = {0.0};

    for (int i = 0; i < V; ++i) {
        Node* current = adjacencyList[i];
        while (current != nullptr) {
            int neighbor = current->vertex;
            if (communities[i] == communities[neighbor]) {
                mod += current->weight;
            }
            totalWeight += current->weight;
            communityWeights[communities[i]] += current->weight;
            current = current->next;
        }
    }

    mod /= totalWeight;
    for (int i = 0; i < V; ++i) {
        if (communityWeights[i] > 0) {
            double fraction = communityWeights[i] / totalWeight;
            mod -= fraction * fraction;
        }
    }

    return mod;
}

int main() {
    Graph g(5);
    g.addEdge(0, 1, 1.0);
    g.addEdge(0, 2, 1.0);
    g.addEdge(1, 2, 1.0);
    g.addEdge(1, 3, 1.0);
    g.addEdge(3, 4, 1.0);

    int communities[5];
    g.louvainMethod(communities);

    // Output communities
    cout << "Node to Community Mapping:" << endl;
    for (int i = 0; i < 5; ++i) {
        cout << "Node " << i << ": Community " << communities[i] << endl;
    }

    return 0;
}
