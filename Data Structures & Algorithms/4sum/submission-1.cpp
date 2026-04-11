class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for(int i = 0; i< nums.size(); i++){
            if (i>0 && nums[i] == nums[i-1]){ // skip dup i;
                continue;
            }
            for(int j = i+1 ; j<nums.size(); j++){
                if (j > i+1 && nums[j] == nums[j-1]){ // skip dup j;
                    continue;
                }
                int l = j+1;
                int r = nums.size()-1;
                // cout<< i <<endl;
                // cout<<j<<endl;
                // cout<<l<<endl;
                // cout<<r<<endl;
                while(l<r && l<nums.size() && r>j){
                    long long sum = (long long)nums[i] + nums[j] + nums[l] + nums[r];
                    if (sum==target){
                        result.push_back({nums[i] , nums[j] , nums[l] , nums[r]});
                        l++;
                        r--;

                        while(l<r && nums[l] == nums[l-1]){ //skip dup l
                            l++;
                        }
                        while(l<r && nums[r] == nums[r+1]){ // skip dup r
                            r--;
                        }
                    }else if (sum > target){
                        r--;
                    }else{
                        l++;
                    }
                }
            }
        }
        return result;
    }
};