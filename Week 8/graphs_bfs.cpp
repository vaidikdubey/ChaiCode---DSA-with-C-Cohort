#include<iostream>
#include <queue>
using namespace std;

void bfs(int startNode, int adjMatrix[][4], int V, bool visited[]) {
    queue<int> q;
    q.push(startNode);
    visited[startNode] = true;

    while(!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        //Visit all adjacent nodes
        for (int i = 0; i < V; i++) {
            if(adjMatrix[node][i] && !visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int main() {
    int V = 4;
    int adjMatrix[4][4] = {0};

    adjMatrix[0][1] = adjMatrix[1][0] = 1;
    adjMatrix[0][3] = adjMatrix[3][0] = 1;
    adjMatrix[1][2] = adjMatrix[2][1] = 1;
    adjMatrix[2][3] = adjMatrix[3][2] = 1;

    bool visited[4] = {false};

    cout << "DFS Traversal from Node 0:" << endl;
    bfs(0, adjMatrix, V, visited);

    return 0;
}