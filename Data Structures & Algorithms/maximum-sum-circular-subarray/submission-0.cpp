class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int currMax = 0;
        int currMin = 0;
        int total = 0;
        int globalMax = nums[0];
        int globalMin = nums[0];

        for(int i = 0; i< nums.size(); i++){
            currMax += nums[i];
            globalMax = max (currMax, globalMax);
            if (currMax < 0){
                currMax = 0;
            }

            total += nums[i];

            currMin += nums[i];
            globalMin = min (currMin, globalMin);
            if (currMin > 0){
                currMin = 0;
            }
        }

        if (globalMax < 0){
            return globalMax;
        }

        return max (globalMax, total-globalMin);
    }
};