class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
       int l =0;
       int res = INT_MAX;
       int sum = 0;
       for (int r =0; r<nums.size(); r++){
        sum += nums[r];
        while(sum >= target){
            res = min (r-l+1, res);
            sum -= nums[l];
            l++;
        }
       }

       return res == INT_MAX ? 0 : res;
    }
};