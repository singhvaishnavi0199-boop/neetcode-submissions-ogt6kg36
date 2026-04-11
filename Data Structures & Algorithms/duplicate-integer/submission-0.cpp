#include <map>
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        map<int,bool> mp;
        int n = nums.size();
        int i = 0;
        while (i<n){
            if (mp.count(nums[i]) == 1){
                return true;
            }
            mp.insert({nums[i], true});
            i++;
        }
        return false;
    }
};