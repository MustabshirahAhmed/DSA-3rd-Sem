#include <iostream>
#include <climits>
using namespace std;

#define V 100  // Max vertices allowed

int main() {
    int n; // Number of vertices
    int graph[V][V]; // Adjacency matrix

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix (0 if no edge):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];

    int key[V];     // To store minimum edge weight for each vertex
    bool mstSet[V]; // To track vertices included in MST
    int parent[V];  // To store MST edges (parent of each vertex)

    // Initialize all keys as infinite and mstSet[] as false
    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    // Start from vertex 0
    key[0] = 0;
    parent[0] = -1; // First node is always root of MST

    for (int count = 0; count < n - 1; count++) {
        // Find vertex with minimum key value not yet in MST
        int u = -1;
        int minKey = INT_MAX;
        for (int v = 0; v < n; v++) {
            if (!mstSet[v] && key[v] < minKey) {
                minKey = key[v];
                u = v;
            }
        }

        // Include chosen vertex in MST
        mstSet[u] = true;

        // Update key and parent of adjacent vertices of u
        for (int v = 0; v < n; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    // Print MST
    cout << "\nEdges in MST:\n";
    int totalWeight = 0;
    for (int i = 1; i < n; i++) {
        cout << parent[i] << " - " << i << " : " << graph[parent[i]][i] << endl;
        totalWeight += graph[parent[i]][i];
    }
    cout << "Total weight of MST: " << totalWeight << endl;

    return 0;
}
