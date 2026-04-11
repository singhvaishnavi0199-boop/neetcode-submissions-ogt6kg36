class UnionFind{
    private:
        vector<int> parent;
        vector<int> rank;
    public:
        UnionFind(int n){
            parent.resize(n);
            rank.assign(n,1);
            for(int i=0; i<n ; i++){
                parent[i] = i;
            }
        }

        int find(int x){
            if (x == parent[x]){
                return x;
            }

            return parent[x] = find(parent[x]);
        }

        bool unionByRank(int x, int y){
            int px = find(x);
            int py = find(y);

            if (px== py){
                return false;
            }

            if(rank[px]> rank[py]){
                parent[py] = px;
            }else if (rank[px] < rank[py]){
                parent[px] = py;
            }else{
                parent[py] = px;
                rank[px]++;
            }

            return true;
        }

};


class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        UnionFind u(n+1);
        for(auto edge : edges){
            if (!u.unionByRank(edge[0], edge[1])){
                return edge;
            }
        }
        return {};
    }
};
