// class Solution {
// public:
//     int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
//     }
// };

/*
// build adj list u->v (t)
// bfs (k)
// q -minHeap
*/

// #include <bits/stdc++.h>
// using namespace std;

class Solution{
    public:
        int networkDelayTime(vector<vector<int>>& times, int n, int k) {
            // build adj list
            unordered_map<int, vector<pair<int,int>>> adj;
            for(auto &time: times){
                int src = time[0];
                int dest = time[1];
                int t = time[2];
                if (adj.count(src)==0){
                    adj[src] = {};
                }
                adj[src].push_back({dest,t});
            }
            // visited
            unordered_set<int> visited;

            // minHeap - time, dest
            priority_queue<pair<int,int> , vector<pair<int,int>> , greater<>> minHeap;

            //starting with kth node
            minHeap.push({0,k});

            // // minTime
            // int minTime = INT_MAX; 

            // bfs - till the Heap becomes empty
            while(!minHeap.empty()){
                auto [currTime , node] = minHeap.top();
                minHeap.pop();

                if (visited.count(node)!=0){
                    continue;
                }
                visited.insert(node);

                if (visited.size()== n){
                    return currTime;
                }

                for(auto &neigh: adj[node]){
                    int time = neigh.second;
                    int nextNode = neigh.first;
                    if (visited.count(nextNode) == 0){
                        minHeap.push({currTime+time, nextNode});
                    }
                }
            }

            return -1;

        }

};

// int main(){

// }