#include <iostream>
#include <vector>
#include <queue>
using namespace std;


vector<int> topologicalSort(vector<vector<int>>&adj){


    vector<int>ans;

    int V = adj.size();
    vector<int>inDegree(V, 0);


    for(int i = 0; i < V; i++){
        for(int j = 0; j < adj[i].size(); j++){
            inDegree[adj[i][j]]++;
        }
    }

    // Initialize a queue
    queue<int>q;

    // Insert those elements into queue which have indgeree 0
    for(int i = 0; i < inDegree.size(); i++){
        if(!inDegree[i]){
            q.push(i);
        }
    }


    while(!q.empty()){
        
        int node = q.front();
        ans.push_back(node);
        q.pop();

        for(int j = 0; j < adj[node].size(); j++){
            inDegree[adj[node][j]]--;

            if(inDegree[adj[node][j]] == 0){
                q.push(adj[node][j]);
            }
        }
    }


    return ans;
}


int main() {
    int V = 6;
    vector<vector<int>> adj(V);

    // Add directed edges
    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    vector<int>res = topologicalSort(adj);

    for(int elem : res){
        cout<<elem<<" ";
    }

    return 0;
}