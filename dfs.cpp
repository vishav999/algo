#include <iostream>
#include <vector>

using namespace std;

class Graph {
private:
    int V; // number of vertices
    vector<vector<int>> adjList; // adjacency list representation of graph

    void DFSUtil(int v, vector<bool>& visited) {
        visited[v] = true;
        cout << v << " ";

        for (int u : adjList[v]) {
            if (!visited[u]) {
                DFSUtil(u, visited);
            }
        }
    }

public:
    Graph(int V) {
        this->V = V;
        adjList.resize(V);
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void DFS(int start) {
        vector<bool> visited(V, false);
        DFSUtil(start, visited);
    }
};

int main() {
    // create a graph with 6 vertices
    Graph g(6);

    // add edges to the graph
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);

    // perform DFS starting from vertex 0
    cout << "DFS traversal starting from vertex 0: ";
    g.DFS(0);

    return 0;
}
