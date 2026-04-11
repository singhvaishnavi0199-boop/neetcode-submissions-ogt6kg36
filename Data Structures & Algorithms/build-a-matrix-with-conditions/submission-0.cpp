class Solution {
private:
    vector<int> topoSort(int k , vector<vector<int>> edges){
        // initialize result
        vector<int> topoSort;
        // build adj
         // indegree
        unordered_map<int, vector<int>> adj; //check if need to iniatialize
        vector<int> indegree(k+1, 0);
        for(int i=0 ;i<edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            indegree[edges[i][1]]++;
        }
        // push all 0 indegree in queue
        queue<int> q;
        for(int i = 1; i<=k ;i++){
            if (indegree[i]==0){
                q.push(i);
            }
        }
        // bfs
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topoSort.push_back(node);

            for(int i =0; i<adj[node].size(); i++){
                int neigh = adj[node][i];
                indegree[neigh]--;
                if(indegree[neigh] == 0){
                    q.push(neigh);
                }
            }
        }
        // if result len < k , then return empty array
        if (topoSort.size()<k){
            return {};
        }else{
            return topoSort;
        }
    }
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> rowOrder = topoSort(k , rowConditions);
        if (rowOrder.size()== 0){
            return {};
        }
        vector<int> colOrder = topoSort(k, colConditions);
        if(colOrder.size()==0){
            return {};
        }

        unordered_map<int, int> valToRow;
        unordered_map<int, int> valToCol;

        for(int i=0; i<k ;i++){
            valToRow[rowOrder[i]]=i;
            valToCol[colOrder[i]]=i;
        }

        vector<vector<int>> res(k, vector<int> (k,0));
        for(int i =1; i <=k ; i++){
            int r = valToRow[i];
            int c = valToCol[i];
            res[r][c] = i;
        }
        return res;
    }
};