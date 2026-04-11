class UnionFind {
private :
    vector <int> parent;
    vector<int> rank;

public: 
    UnionFind(int n){
        parent.resize(n);
        for(int i = 0; i<n ; i++){
            parent[i] = i;
        }
        rank.resize(n, 0);
    }

    int find(int x){ // parent
        if (parent[x] == x){
            return parent[x];
        }
        return find(parent[x]);
    }

    void unionParent(int x, int y){ // unite parent
        int px = find(x);
        int py = find(y);

        if(px == py){
            return;
        }

        if(rank[px] == rank[py]){
            parent[py] = px;
            rank[px]++;
        }else if (rank[px]< rank[py]){
            parent[px] = py;
        }else{
            parent[py] = px;
        }
        return;
    }
};

class Solution {

private:
    int kruskal(int n, vector<vector<int>>& edges, int skip , int force){
        UnionFind uf(n);
        int mst = 0;
        int count = 0;

        // include force edge first
        if (force != -1){
            int u = edges[force][0];
            int v = edges[force][1];
            int w = edges[force][2];
            mst += w;
            uf.unionParent(u, v);
            count++;
        }
        for(int i = 0; i< edges.size(); i++){
            if (skip == i){
                continue;
            }
            if (uf.find(edges[i][0]) == uf.find(edges[i][1])){
                continue;
            }else{
                mst += edges[i][2];
                count++;
                uf.unionParent(edges[i][0], edges[i][1]);
            }
        }

        if (count == n-1){
            return mst;
        }else{
            return INT_MAX;
        }

    }

    static bool cmp(vector<int> &a, vector<int> &b){
        return a[2] < b[2];
    }

public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        
        int e = edges.size();

        // newEdges with index; // u, v, w, i
        vector<vector<int>> newEdges;
        for(int i = 0; i< e ; i++){
            vector<int> edge = edges[i];
            edge.push_back(i);
            newEdges.push_back(edge);
        }

        // sort newEdges
        sort(newEdges.begin(), newEdges.end(), cmp);

        // find base mst
        int base = kruskal(n, newEdges, -1, -1);
        cout<<"base "<<base<<endl;

        //critical , pseudo 
        vector<int> critical, pseudo;

        // iterate on all edges
        for(int i = 0; i<e ; i++){
            // skip edges
            int skipMST = kruskal(n, newEdges, i, -1);
            cout<<"skipMST "<<skipMST<<endl;
            if (base < skipMST){
                critical.push_back(newEdges[i][3]);
            }else{
                int forceMST = kruskal(n, newEdges , -1, i);
                cout<<"forceMST "<<forceMST<<endl;
                if (base == forceMST){
                    pseudo.push_back(newEdges[i][3]);
                }
            }
        }

        vector<vector<int>> res;
        res.push_back(critical);
        res.push_back(pseudo);
        return res;
    }
};