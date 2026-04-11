// bfs
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
        
        for(int i=0; i<n; i++){
            if(!visited[i]){
                queue<int> q;
                q.push(i);
                visited[i]= true;

                while(!q.empty()){
                    int node = q.front();
                    q.pop();

                    for(auto neigh: adj[node]){
                        if(!visited[neigh]){
                            q.push(neigh);
                            visited[neigh] = true;
                        }
                    }
                }
                components++;
            }
        }

        return components;
    }
};
