class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSumCount;
        prefixSumCount[0] = 1;
        int result = 0;
        int prefixSum = 0;

        for(int i=0; i<nums.size(); i++){
            prefixSum += nums[i];
            int diff = prefixSum - k;
            result += prefixSumCount[diff];
            // if (prefixSumCount.find(diff) != prefixSumCount.end()){
                
            // }
            prefixSumCount[prefixSum]++;
        }

        return result;
    }
};