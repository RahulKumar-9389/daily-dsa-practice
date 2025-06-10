#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool bfs(vector<vector<int>> &graph, vector<int> &color, int start)
{

    // Initialize queue
    queue<int> q;
    q.push(start);
    color[start] = 0;

    while (!q.empty())
    {

        int node = q.front();
        q.pop();

        for (int neighbor : graph[node])
        {
            // .. if not colored
            if (color[neighbor] == -1)
            {
                color[neighbor] = 1 - color[node];
                q.push(neighbor);
            }
            else if (color[neighbor] == color[node])
            {
                return false;
            }
        }
    }

    return true;
}

bool isBipartite(vector<vector<int>> &graph)
{
    int n = graph.size();

    vector<int> color(n, -1);

    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
        {
            if (!bfs(graph, color, i))
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{

    vector<vector<int>> graph = {
        {1, 2, 3},
        {0, 2},
        {0, 1, 3},
        {0, 2}};
    if (isBipartite(graph))
    {
        cout << "Given graph is a bipartite graph!!";
    }
    else
    {
        cout << "Given graph is not a bipartite graph!!";
    }
    return 0;
}