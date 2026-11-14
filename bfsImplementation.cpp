#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph {
    int V; // Number of vertices
    vector<vector<int>> adj; // Adjacency list for graph representation

public:
    // Constructor
    Graph(int vertices) {
        V = vertices;
        adj.resize(V);
    }

    // Function to add a directed edge to the graph
    // For undirected graphs, call addEdge for both directions (u -> v and v -> u)
    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    // Function to perform Breadth-First Search from a given source
    void BFS(int startNode) {
        // Track visited nodes to avoid cycles and redundant visits
        vector<bool> visited(V, false);

        // Create a queue for BFS traversal
        queue<int> q;

        // Mark the starting node as visited and push it into the queue
        visited[startNode] = true;
        q.push(startNode);

        cout << "BFS Traversal starting from node " << startNode << ": ";

        while (!q.empty()) {
            // Dequeue a vertex from the front of the queue
            int curr = q.front();
            q.pop();
            cout << curr << " ";

            // Iterate through all adjacent neighbors of the current vertex
            for (int neighbor : adj[curr]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true; // Mark as visited immediately when pushing
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }
};

int main() {
    // Create a graph with 5 vertices (0 to 4)
    Graph g(5);

    // Add edges to form the graph
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 4);

    // Perform BFS starting from vertex 0
    g.BFS(0);

    return 0;
}
