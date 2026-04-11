class Solution {
private:
    int prims(int n , vector<vector<int>>& edges , int skip , int force){
        // build adj list, skipping the edge if mentioned
        // u - v, weight
        vector<vector<pair<int,int>>> adj(n);
        for(int i = 0; i<edges.size(); i++){
            if (i == skip){
                continue;
            }else{
                adj[edges[i][0]].push_back({edges[i][1] , edges[i][2]});
                adj[edges[i][1]].push_back({edges[i][0] , edges[i][2]});
            }
        }

        // min Heap
        // total weight
        // count of vertices
        // visited

        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<>> minHeap; // weight, v
        int mst = 0;
        int count = 0;
        vector<bool> visited(n,false);

        // including forced edge first ,if no edge is forced push (0,0)
        if (force != -1){
            int u = edges[force][0];
            int v = edges[force][1];
            int w = edges[force][2];
            mst += w;
            visited[u] = true;
            count++;
            minHeap.push({0, v});

            // push real neighbors of u
            for (auto &nbr : adj[u]) {
                if (!visited[nbr.first]) {
                    minHeap.push({nbr.second, nbr.first});
                }
            }
            // mst += w;
            // visited[u] = true;
            // count++;
            // mst += w;
            // count++;
            // minHeap.push({0,v});
            // visited[u] = true;
        }else{
            minHeap.push({0,0});
        }

        while(!minHeap.empty() && count<n){
            auto [weight, v] = minHeap.top();
            cout<<weight<<" "<<v<<endl;
            minHeap.pop();

            if (visited[v]){
                continue;
            }

            visited[v] = true;
            mst += weight;
            cout<<mst<<endl;
            count++;

            for(int i = 0; i< adj[v].size(); i++){
                if (!visited[adj[v][i].first]){
                    minHeap.push({adj[v][i].second, adj[v][i].first});
                }
            }

        }

        if (count == n){
            return mst;
        } else{ 
            return INT_MAX;
            } 

    }
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        int e = edges.size();
        vector<int> critical, psuedo;

        int baseMST = prims(n, edges , -1, -1);
        cout<<baseMST<<endl;

        for(int i = 0; i<e ; i++){
            // skipping this edge, will mst > base
            int skipMST = prims(n, edges, i, -1);
            if (skipMST > baseMST){
                critical.push_back(i);
            }else{
                // check if including this edge , mst == base
                int forceMST = prims(n, edges, -1, i);
                if(forceMST == baseMST){
                    psuedo.push_back(i);
                }
            }
        }

        vector<vector<int>> res;
        res.push_back(critical);
        res.push_back(psuedo);
        return res;
    }
};