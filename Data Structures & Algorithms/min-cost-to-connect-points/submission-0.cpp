class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        unordered_set<int> visited;
        priority_queue< pair<int,int> , vector<pair<int,int>> , greater<pair<int, int>>> minHeap;
        int result = 0;

        minHeap.push({0,0}); //cost,index

        while(!minHeap.empty()){
            auto [cost , index] = minHeap.top();
            minHeap.pop();

            if (visited.find(index)==visited.end()){
                visited.insert(index);
            result = result + cost;
            if (visited.size()== points.size()){
                return result;
            }
            for(int i =0; i<points.size() ; i++){
                if(i==index || visited.find(i)!=visited.end()){
                    continue;
                }
                int sum = abs(points[i][0]- points[index][0]) + abs(points[i][1]- points[index][1]);
                minHeap.push({sum, i});
            }
            }
        }
        return result;
    }
};
