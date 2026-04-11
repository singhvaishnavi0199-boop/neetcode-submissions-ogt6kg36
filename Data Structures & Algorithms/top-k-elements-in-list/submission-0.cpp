#include <unordered_map>
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector <int> ans;
        unordered_map <int, int> mp;
        for (int i =0 ; i<n ; i++){
            mp[nums[i]]++;
        }

        vector <vector<int>> v (n+1);
        for (auto &it :mp){
            v[it.second].push_back(it.first);
        }

        for (int i = n ; i>0 ; i--){
            for (int j = 0 ; j< v[i].size(); j++){
                ans.push_back(v[i][j]);
                if (ans.size()==k){
                    return ans;
                }
            }
        }
        return ans; // safety return
    }
};
