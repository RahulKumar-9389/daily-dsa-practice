#include <iostream>
#include <vector>
using namespace std;

// DFS function to detect a cycle in an undirected graph
bool dfs(int node, int parent, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            if (dfs(neighbor, node, adj, visited)) {
                return true;
            }
        } else if (neighbor != parent) {
            return true; // Found a back edge → cycle
        }
    }

    return false;
}

// Function to check cycle in all components
bool hasCycle(int n, vector<vector<int>>& adj) {
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, adj, visited)) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    int n = 8; // Number of nodes

    // Initialize graph with 8 nodes
    vector<vector<int>> adj(n);

    
    adj[0] = {1, 2};
    adj[1] = {0, 3};
    adj[2] = {0, 4};
    adj[3] = {1, 4};  // Forms a cycle: 1-3-4-2-0-1
    adj[4] = {2, 3};

    adj[5] = {6};    
    adj[6] = {5, 7};
    adj[7] = {6};

    if (hasCycle(n, adj)) {
        cout << "Cycle detected in the graph.\n";
    } else {
        cout << "No cycle found in the graph.\n";
    }

    return 0;
}
