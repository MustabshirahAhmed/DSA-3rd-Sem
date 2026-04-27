#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void printList(vector<int> answer) {
    for (int i = 0; i < answer.size(); i++) {
        if (i == answer.size() - 1) cout << answer[i];
        else cout << answer[i] << " => ";
    }
    cout << endl;
}

vector<int> BFS(vector<pair<int, int> > adjacencyList[], int vertices, int edges, int startingPoint) {
    queue<int> q;
    vector<bool> visited(vertices, 0);
    vector<int> answer;
    q.push(startingPoint);
    visited[startingPoint] = 1;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        answer.push_back(node);

        for (int i = 0; i < adjacencyList[node].size(); i++) {
            int adjNode = adjacencyList[node][i].first;
            if (!visited[adjNode]) {
                visited[adjNode] = 1;
                q.push(adjNode);
            }
        }
    }
    return answer;
}

void DFS(int node, vector<pair<int, int> > adjacencyList[], vector<bool>& visited, vector<int>& answer) {
    visited[node] = 1;
    answer.push_back(node);

    for (int i = 0; i < adjacencyList[node].size(); i++) {
        int adjNode = adjacencyList[node][i].first;
        if (!visited[adjNode]) {
            DFS(adjNode, adjacencyList, visited, answer);
        }
    }
}
void displayAdjacencyMatrix(vector<pair<int, int> > adjacencyList[], int vertices) {
    int matrix[vertices][vertices] = {0}; // assuming max 100 vertices — you can adjust

    // Fill matrix from adjacency list
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < adjacencyList[i].size(); j++) {
            int adjNode = adjacencyList[i][j].first;
            matrix[i][adjNode] = 1; // you can use adjacencyList[i][j].second if weights are to be shown
        }
    }

    // Display matrix
    cout << "\nAdjacency Matrix:\n    ";
    for (int i = 0; i < vertices; i++)
        cout << i << " ";
    cout << endl;

    for (int i = 0; i < vertices; i++) {
        cout << i << " | ";
        for (int j = 0; j < vertices; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    cout << "Welcome to muse tracker: ";
    int vertices;
    int edges;
    int startingPoint;
    cout << "Enter vertices and then edges: ";
    cin >> vertices;
    cin >> edges;

    vector<pair<int, int> > adjacencyList[vertices];
    vector<int> answer;
    vector<int> answer2;
    vector<bool> visited(vertices, 0);

    int row, column;
    int weight = 0;

    for (int i = 0; i < edges; i++) {
        cout << "enter the entries as (x,y) coordinate: ";
        cin >> row;
        cin >> column;
        adjacencyList[row].push_back(make_pair(column, weight));
        adjacencyList[column].push_back(make_pair(row, weight));
    }

    cout << "please enter starting Point: ";
    cin >> startingPoint;

    cout << "Mouse Tracking (BFS): ";
    answer = BFS(adjacencyList, vertices, edges, startingPoint);
    printList(answer);

    cout << "Mouse Tracking (DFS): ";
    DFS(startingPoint, adjacencyList, visited, answer2);
    printList(answer2);

    // displayAdjacencyMatrix()

    return 0;
}
