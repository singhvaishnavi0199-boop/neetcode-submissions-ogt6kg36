class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // adjacency map
        unordered_map<string, vector<string>> adj;
        for(auto &ticket : tickets){
            adj[ticket[0]].push_back(ticket[1]);
        }

        for(auto &[src,dest]: adj){
            sort(dest.rbegin(), dest.rend());
        }
        // result vector
        vector<string> result;
        // call dfs
        dfs("JFK", adj, result);
        reverse(result.begin(),result.end());
        return result; 
    }

private:
    void dfs(string source , unordered_map<string, vector<string>>&adj ,vector<string>& result){
        while(!adj[source].empty()){
            string dest = adj[source].back();
            adj[source].pop_back();
            dfs(dest, adj, result);
        }
        result.push_back(source);
    }
};
