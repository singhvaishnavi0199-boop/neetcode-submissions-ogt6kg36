class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        //since there is one extra edge
        int n = edges.size();

        //parent
        vector<int> parent(n+1);
        for(int i=0; i<n+1; i++){
            parent[i] = i;
        }

        //rank
        vector<int> rank(n+1, 1);

        //
        for( const auto &edge: edges){
            if(!unionFunc(edge[0], edge[1], parent, rank)){
                return edge;
            }
        } 
        return {};
        
    }

    int find(int node, vector<int>& parent){
        if (node != parent[node]){
            parent[node] = find(parent[node], parent);
        }
        return parent[node];
    }

    bool unionFunc(int node1, int node2, vector<int>& parent,vector<int>&rank ){
        int p1 = find(node1, parent);
        int p2 = find(node2, parent);
        if(p1 == p2){ // if nodes already belong to the same parent, then it is a cycle
            return false; 
        }
        if (rank[p1] <= rank[p2]) {
            parent[p2] = p1;
            rank[p2] += rank[p1];
        } else {
            parent[p1] = p2;
            rank[p1] += rank[p2];
        }
        return true;
    }
};
