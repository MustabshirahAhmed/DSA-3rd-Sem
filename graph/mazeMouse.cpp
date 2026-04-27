#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void printMaze(vector<vector<char> > &maze) {
    cout << "\nMaze State:\n";
    for (int i = 0; i < maze.size(); i++) {
        for (int j = 0; j < maze[0].size(); j++) {
            cout << maze[i][j] << " ";
        }
        cout << endl;
    }
}

void BFS(vector<vector<char> > &maze, int startX, int startY) {
    int n = maze.size();
    int m = maze[0].size();

    queue<pair<int, int> > q;
    q.push({startX, startY});
    maze[startX][startY] = 'P';

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];

            if (newX >= 0 && newX < n && newY >= 0 && newY < m && maze[newX][newY] == '0') {
                maze[newX][newY] = 'P';
                q.push({newX, newY});
            }
        }
    }
}

int main() {
    int n, m;
    cout << "Enter maze dimensions (rows cols): ";
    cin >> n >> m;

    vector<vector<char> > maze(n, vector<char>(m));
    cout << "Enter the maze matrix (0 for open, 1 for blocked):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> maze[i][j];

    int startX, startY;
    cout << "Enter starting point (row col): ";
    cin >> startX >> startY;

    if (maze[startX][startY] == '1') {
        cout << "Starting point is blocked!\n";
        return 0;
    }

    BFS(maze, startX, startY);

    cout << "\nFinal Maze with Visited Path (P):\n";
    printMaze(maze);

    return 0;
}
