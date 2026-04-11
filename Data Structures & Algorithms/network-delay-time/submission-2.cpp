class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // build adj
        // visited set
        // min heap
        // time
        // if visited set 
        unordered_map<int, vector<vector<int>>> adj;
        for(int i=0; i<times.size(); i++){
            adj[times[i][0]].push_back({times[i][1], times[i][2]});
        }

        unordered_set<int> visited;
        priority_queue<pair<int,int>, vector<pair<int,int>> , greater<>> minHeap;
        minHeap.push({0,k});

        while(!minHeap.empty()){
            auto [time , node] = minHeap.top();
            minHeap.pop();
            visited.insert(node);

            if (visited.size()== n){
                return time;
            }

            for(auto network : adj[node]){
                int nextNode = network[0];
                int nextTime = network[1];

                if (!visited.count(nextNode)){
                    minHeap.push({nextTime + time , nextNode});
                }
            }
        }

        return -1;
    }
};
