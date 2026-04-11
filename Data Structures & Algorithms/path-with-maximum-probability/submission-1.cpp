class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        // build adj
        unordered_map<int, vector<pair<int, double>>> adj;
        for(int i=0; i< edges.size(); i++){
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }

        // queue<pair<int,double>> q;
        priority_queue<pair<double,int>> maxHeap;
        unordered_set<int> visited;
        maxHeap.push({1.0, start_node});
        // visited.insert(start_node);

        while(!maxHeap.empty()){
            auto [prob, node] = maxHeap.top();
            maxHeap.pop();
            visited.insert(node);

            if (node == end_node){
                return prob;
            }

            for(auto &nodes : adj[node]){
                if (!visited.count(nodes.first)){
                    maxHeap.push({prob * nodes.second, nodes.first});
                }
            }
        }

        return 0.0;
    }
};