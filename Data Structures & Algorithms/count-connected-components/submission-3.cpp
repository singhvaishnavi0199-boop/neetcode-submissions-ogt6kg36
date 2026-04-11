// --- bfs ---

// class Solution {
// public:
//     int countComponents(int n, vector<vector<int>>& edges) {
//         int result = 0;
//         // adjacency list (mapping of connected nodes)
//         vector<vector<int>> adj(n);
//         // visited set
//         unordered_set<int> visited;

//         // for loop
//         for(const auto &edge: edges){
//             adj[edge[0]].push_back(edge[1]);
//             adj[edge[1]].push_back(edge[0]);
//         }
//         // bfs -> increment

//         for(int i =0; i<n ;i++){
//             if(!visited.count(i)){
//                 bfs(adj, i , visited);
//                 result++;
//             }
//         }

//         return result;
//     }

//     void bfs(vector<vector<int>>&adj , int node ,unordered_set<int>& visited){
//         queue<int> q;
//         q.push(node);
//         visited.insert(node);

//         while(!q.empty()){
//             int n = q.front();
//             q.pop();

//             for(int i=0; i< adj[n].size(); i++){
//                 if (!visited.count(adj[n][i])){
//                     q.push(adj[n][i]);
//                     visited.insert(adj[n][i]);
//                 }
//             }
//         }
//     }
// };


// --- dfs ----
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int result = 0;
        // adjacency list (mapping of connected nodes)
        vector<vector<int>> adj(n);
        // visited set
        unordered_set<int> visited;

        // for loop
        for(const auto &edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        // dfs -> increment

        for(int i =0; i<n ;i++){
            if(!visited.count(i)){
                dfs(adj, i , visited);
                result++;
            }
        }

        return result;
    }

    void dfs(vector<vector<int>>&adj , int node ,unordered_set<int>& visited){
        if (visited.count(node)){
            return;
        }

        visited.insert(node);
        for(int i =0 ; i< adj[node].size(); i++){
            if (!visited.count(adj[node][i])){
                dfs(adj, adj[node][i], visited);
            }
        }
    }
};

