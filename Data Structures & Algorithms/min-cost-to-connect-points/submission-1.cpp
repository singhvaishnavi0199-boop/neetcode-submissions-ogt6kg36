class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        unordered_set<int> visited; // indexes
        priority_queue<pair<int,int> , vector<pair<int,int>>, greater<>> minHeap; //cost, index
        int minCost = 0; // result

        minHeap.push({0,0});

        while(!minHeap.empty()){
            auto [cost, node] = minHeap.top();
            minHeap.pop();

            if (visited.count(node) != 0){
                continue;
            }

            visited.insert(node);

            minCost += cost;

            if (visited.size()==n){
                return minCost;
            }

            for(int i = 0; i<n ; i++){
                if (node == i){
                    continue;
                }
                if (visited.count(i) != 0){
                    continue;
                }

                int diff = abs(points[i][0]-points[node][0]) + abs(points[i][1]-points[node][1]);
                minHeap.push({diff, i});

            }

        }

        return -1;

    }
};
