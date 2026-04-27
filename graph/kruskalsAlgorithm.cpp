#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Structure to store an edge
struct Edge {
    int src, dest, weight;
};

// Compare function to sort edges by weight
bool compareEdges(Edge a, Edge b) {
    return a.weight < b.weight;
}

// Find function with path compression
int findParent(int v, int parent[]) {
    if (parent[v] == v)
        return v;
    return parent[v] = findParent(parent[v], parent);
}

// Union function
void unionSets(int u, int v, int parent[]) {
    int parentU = findParent(u, parent);
    int parentV = findParent(v, parent);
    if (parentU != parentV)
        parent[parentV] = parentU;
}

int main() {
    int vertices, edges;
    cout << "Enter number of vertices and edges: ";
    cin >> vertices >> edges;

    vector<Edge> edgeList(edges);

    cout << "Enter edges (source destination weight):\n";
    for (int i = 0; i < edges; i++) {
        cin >> edgeList[i].src >> edgeList[i].dest >> edgeList[i].weight;
    }

    // Sort edges by weight
    sort(edgeList.begin(), edgeList.end(), compareEdges);

    // Initialize parent array for union-find
    int parent[100];  // Assuming max 100 vertices; increase if needed
    for (int i = 0; i < vertices; i++)
        parent[i] = i;

    vector<Edge> mst;
    int totalCost = 0;

    for (int i = 0; i < edges; i++) {
        int u = edgeList[i].src;
        int v = edgeList[i].dest;

        // If adding this edge doesn’t form a cycle
        if (findParent(u, parent) != findParent(v, parent)) {
            mst.push_back(edgeList[i]);
            totalCost += edgeList[i].weight;
            unionSets(u, v, parent);
        }

        // Stop if MST has (vertices - 1) edges
        if (mst.size() == vertices - 1)
            break;
    }

    cout << "\nMinimum Spanning Tree edges:\n";
    for (int i = 0; i < mst.size(); i++) {
        cout << mst[i].src << " -- " << mst[i].dest << " (weight: " << mst[i].weight << ")\n";
    }

    cout << "Total cost of MST: " << totalCost << endl;

    return 0;
}
