class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        unordered_map<int,int> mp; //position : passenger
        for (vector<int> trip : trips){
            mp[trip[1]] = mp[trip[1]] + trip[0]; // pickup position
            mp[trip[2]] = mp[trip[2]] - trip[0]; //drop off position
        }

        priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for (auto ele: mp){
            pq.push({ele.first, ele.second});
        }

        int passCount = 0;
        while (!pq.empty()){
            if (passCount> capacity){
                return false;
            }
            passCount += pq.top().second;
            pq.pop();
        }
        return true;
    }
};