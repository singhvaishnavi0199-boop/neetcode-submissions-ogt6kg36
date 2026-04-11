class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        // source - [<target, time>]
        unordered_map<int , vector<pair<int,int>>> edges;
        for(auto &time: times){
            edges[time[0]].push_back({time[1], time[2]});
        }

        // dijsktra - current time for network to reach
        vector<int> currTime (n+1, INT_MAX);
        currTime[k] = 0;

        //min heap
        priority_queue< pair<int,int> , vector<pair<int,int>> , greater<>> minHeap;
        minHeap.push({0,k});

        //no of nodes visited
        unordered_set<int> visited;

        while(!minHeap.empty()){
            int timeDelay = minHeap.top().first;
            int source = minHeap.top().second;
            
            minHeap.pop();
            visited.insert(source);

            if(visited.size() == n){
                return timeDelay;
            }

            for(auto &edge: edges[source]){
                int target = edge.first;
                int time = edge.second;

                int newTime = timeDelay + time;
                if (newTime < currTime[target]){
                    currTime[target] = newTime;
                    minHeap.push({newTime, target});
                }
            }
        }
        return -1;

    }
};
