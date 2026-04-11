// union find
class UnionFind{
    private:
        vector<int> parent;
        vector<int> rank;
    public:
    UnionFind(int n){
        parent.resize(n);
        for(int i=0; i<n;i++){
            parent[i] = i;
        }
        rank.assign(n,1);
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
        if (px == py){
            return false; // already same parent, no union
        }

        if(rank[px] > rank[py]){
            parent[py] = px;
        }else if (rank[py] > rank[px]){
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
    int countComponents(int n, vector<vector<int>>& edges) {
        int res = n;
        UnionFind u(n);
        for(auto& edge : edges){
            if (u.unionByRank(edge[0], edge[1])){
                res--;
            }
        }
        return res;

    }
};
