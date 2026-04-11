class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for (int i =0; i<nums.size(); i++){
            if (i+1 == nums.size()){
                break;
            }
            if (i> 0 && nums[i] == nums[i-1]){
                continue;
            }
            int l = i+1;
            int r = nums.size()-1;
            int diff = 0 - nums[i];
            while (l<r){
                if (nums[l] + nums[r] > diff){
                    r--;
                }else if (nums[l] + nums[r] < diff){
                    l++;
                }else{
                    ans.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                    while (l< r && nums[l] == nums[l-1]){
                        l++;
                    }
                }
            }
        }

        return ans;
    }
};
