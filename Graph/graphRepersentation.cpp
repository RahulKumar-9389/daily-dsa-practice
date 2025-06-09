#include <iostream>
#include <vector>
using namespace std;

int main()
{

    int n, m;

    cout << "Enter the number of vertices: ";
    cin >> n;

    cout << "Enter the number of edges: ";
    cin >> m;

    // Create a adjacency list
    vector<vector<int>> adj(n);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // print adjacency list
    for (int i = 0; i < n; i++)
    {
        cout << "Node " << i << ": ";
        for (int neighbor : adj[i])
        {
            cout << neighbor << " ";
        }
        cout << endl;
    }

    return 0;
}