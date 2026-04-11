class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        int maj = nums.size()/3;
        vector<int> res;
        for(auto& pair : mp){
            if (pair.second > nums.size()/3){
                res.push_back(pair.first);
            }
        }
        return res;

    }
};