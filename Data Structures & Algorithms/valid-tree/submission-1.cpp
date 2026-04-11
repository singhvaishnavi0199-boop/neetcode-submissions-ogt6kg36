class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // no of edges = n-1 in undirected acyclic graph that is a tree
        if (edges.size()!=n-1){
            return false;
        }

        // all nodes must be connected.
        queue <int> q;
        q.push(0);

        unordered_map<int, vector<int>> mp;
        unordered_set<int> visited;
        for(int i=0;i<edges.size();i++){
            int first = edges[i][0];
            int second = edges[i][1];
            mp[first].push_back(second);
            mp[second].push_back(first);
        }

        while(!q.empty()){
            int curr = q.front();
            q.pop();
            visited.insert(curr);
            for(int i =0 ; i<mp[curr].size(); i++){
                if(!visited.count(mp[curr][i])){
                    q.push(mp[curr][i]);
                }
            }
        }

        if(visited.size()==n){
            return true;
        }else{
            return false;
        }
    }
};
