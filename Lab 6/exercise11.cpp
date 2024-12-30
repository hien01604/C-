// Phạm Thị Minh Hiền
// 22520422

#include <iostream>
using namespace std;

const int INF = 1e9; // Giá trị lớn thay thế cho INT_MAX

int findMinDistance(int dist[], bool visited[], int N) {
    int minDist = INF, minIndex = -1;

    for (int i = 0; i < N; ++i) {
        if (!visited[i] && dist[i] < minDist) {
            minDist = dist[i];
            minIndex = i;
        }
    }

    return minIndex;
}

void dijkstra(int graph[100][100], int N, int source, int destination) {
    int dist[N];
    bool visited[N];
    int previous[N];

    for (int i = 0; i < N; ++i) {
        dist[i] = INF;
        visited[i] = false;
        previous[i] = -1;
    }
    dist[source] = 0;

    for (int count = 0; count < N - 1; ++count) {
        int u = findMinDistance(dist, visited, N);
        if (u == -1 || dist[u] == INF) break;
        visited[u] = true;

        for (int v = 0; v < N; ++v) {
            if (!visited[v] && graph[u][v] != 0 && dist[u] != INF
                && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                previous[v] = u;
            }
        }
    }

    cout << "Shortest distance from node " << source << " to node " << destination << ": ";
    if (dist[destination] == INF) {
        cout << "Unreachable\n";
        return;
    }
    cout << dist[destination] << "\n";

    cout << "Path: ";
    int path[100], pathSize = 0;
    for (int at = destination; at != -1; at = previous[at]) {
        path[pathSize++] = at;
    }
    for (int i = pathSize - 1; i >= 0; --i) {
        cout << path[i];
        if (i > 0) cout << " -> ";
    }
    cout << endl;
}

int main() {
    int N = 6;
    int graph[100][100] = {
        {0, 2, 4, 0, 0, 0},
        {2, 0, 1, 7, 0, 0},
        {4, 1, 0, 3, 4, 0},
        {0, 7, 3, 0, 1, 2},
        {0, 0, 4, 1, 0, 5},
        {0, 0, 0, 2, 5, 0}
    };

    int source = 0;
    int destination = 5;

    dijkstra(graph, N, source, destination);

    return 0;
}
