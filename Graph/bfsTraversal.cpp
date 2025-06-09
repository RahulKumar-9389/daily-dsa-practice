#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector<vector<int>> &adj, int source)
{

    int V = adj.size();

    // Create a visited array
    vector<bool> visited(V, false);

    // Initialize a queue
    queue<int> q;

    visited[source] = true;
    q.push(source);

    while (!q.empty())
    {

        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor : adj[node])
        {
            if (!visited[neighbor])
            {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

int main()
{

    // Initialize a undirected, unweighted graph
    vector<vector<int>> adj = {{1, 2}, {0, 2, 3}, {0, 4}, {1, 4}, {2, 3}};
    bfs(adj, 0);
    return 0;
}