#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(int start, vector<int> adj[], int vertices) {
    vector<bool> visited(vertices, false);  // Track visited nodes
    queue<int> q;

    q.push(start);          // Start from the given node
    visited[start] = true;  // Mark the start node as visited

    cout << "BFS Traversal: ";
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";  // Print the current node

        // Visit all unvisited neighbors
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    cout << endl;
}

int main() {
    int vertices = 5;
    vector<int> adj[vertices];  // Adjacency list

    // Adding edges (undirected graph)
    adj[0] = {1, 2};
    adj[1] = {0, 3, 4};
    adj[2] = {0};
    adj[3] = {1};
    adj[4] = {1};

    bfs(0, adj, vertices);  // Start BFS from node 0

    return 0;
}
