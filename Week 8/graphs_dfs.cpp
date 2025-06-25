#include <iostream>
using namespace std;

void dfs(int startNode, int adjMatrix[][4], int V, bool visited[]) {
    int stack[V];
    int top = -1;

    stack[++top] = startNode;

    while(top >= 0) {
        int node = stack[top--];

        if(!visited[node]) {
            visited[node] = true;
            cout << node << " ";

            //Push adjacent unvisited nodes
            for (int i = V - 1; i >= 0; i--) {
                if(adjMatrix[node][i] && !visited[i]) {
                    stack[++top] = i;
                }
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
    dfs(0, adjMatrix, V, visited);

    return 0;
}