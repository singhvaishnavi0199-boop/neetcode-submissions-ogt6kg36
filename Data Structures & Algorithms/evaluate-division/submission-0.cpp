class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // build adjacency list
        unordered_map <string, vector<pair<string, double>>> adj;
        for(int i =0 ; i<equations.size(); i++){
            string a = equations[i][0];
            string b = equations[i][1];
            adj[a].push_back({b, values[i]});
            adj[b].push_back({a, 1/values[i]});
        }


        //result
        vector<double> result;
        for(int i=0; i<queries.size(); i++){
            string src = queries[i][0];
            string target = queries[i][1];
            result.push_back(bfs(src,target,adj));
        }

        return result;
    }

    double bfs(string src, string target ,unordered_map <string, vector<pair<string, double>>>& adj){
        if (!adj.count(src) || !adj.count(target)){
            return -1.0;
        }

        if (src == target){
            return 1.0;
        }

        unordered_set<string> visited;
        queue<pair<string,double>> q;
        q.push({src, 1.0});
        visited.insert(src);

        while(!q.empty()){
            auto [currSrc, weight] = q.front();
            q.pop();

            if (currSrc== target){
                return weight;
            }

            for(int i=0; i<adj[currSrc].size(); i++){
                if (!visited.count(adj[currSrc][i].first)){
                    q.push({adj[currSrc][i].first, weight * adj[currSrc][i].second});
                    visited.insert(adj[currSrc][i].first);
                }
            }

        }
        return -1.0;
    }
};