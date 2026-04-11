class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);
        int components = 0;

        for(int i = 0; i<n ;i++){
            if (!visited[i]){
                dfs(i, adj, visited);
                cout<<i<<endl;
                components++;
            }
        }
        return components;
    }

    void dfs(int i, vector<vector<int>>&adj,vector<bool>& visited){

        visited[i] = true;

        for(auto neigh: adj[i]){
            if (!visited[neigh]){
                dfs(neigh, adj, visited);
            }
        }
        return;
    }
};
