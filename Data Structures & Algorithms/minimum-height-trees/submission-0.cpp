class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n==1){
            return {0};
        }

        vector<int> result;

        //adj
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        //queue
        queue<int> leaf;

        //edge_count
        vector<int> edge_count(n);
        for(int i=0;i<n;i++){
            edge_count[i]= adj[i].size();
            if(edge_count[i]==1){
                leaf.push(i);
            } 
        }


        while(!leaf.empty()){

            if(n<=2){
                while(!leaf.empty()){
                    int midNode = leaf.front();
                    leaf.pop();
                    result.push_back(midNode);
                }
                return result;
            }
            int size = leaf.size();
            for(int i=0; i<size; i++){
                int node = leaf.front();
                leaf.pop();
                n--;

                //remove the edge
                for(int j =0 ;j<adj[node].size();j++){
                    edge_count[adj[node][j]]--;
                    if (edge_count[adj[node][j]]==1){
                        leaf.push(adj[node][j]);
                    }
                }
            }
        }
        return result;
    }
};