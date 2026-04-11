class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //bellman ford algo

        vector<int> adj (n, INT_MAX);
        adj[src] = 0;

        for(int i = 0 ;i < k+1 ; i++){
            vector<int> temp = adj;
            for(auto& flight:flights){
                int source = flight[0];
                int dest = flight[1];
                int cost = flight[2];

                if(adj[source] == INT_MAX){
                    continue;
                }

                if (adj[source]+ cost < temp[dest]){
                    temp[dest] = adj[source]+ cost;
                }
            }
            adj = temp;
        }

        if(adj[dst] == INT_MAX){
            return -1;
        }else{
            return adj[dst];
        }
    }
};
