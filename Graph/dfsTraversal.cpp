#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void dfs(vector<vector<int>> &adj, vector<bool>&visited, int source)
{
    visited[source] = true;
    cout<<source<<" ";

    for(int neighbor : adj[source]){
        if(!visited[neighbor]){
            dfs(adj, visited, neighbor);
        }
    }


}

int main()
{

    // Initialize a undirected, unweighted graph
    vector<vector<int>> adj = {{1, 2}, {0, 2, 3}, {0, 4}, {1, 4}, {2, 3}};
    int V = adj.size();

    vector<bool>visited(V, false);
    dfs(adj, visited, 0);
    return 0;
}