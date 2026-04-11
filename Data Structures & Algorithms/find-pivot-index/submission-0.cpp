class Solution {
public:
    int pivotIndex(vector<int>& nums) {
       int total = 0;
       for(int i=0; i<nums.size(); i++){
        total += nums[i];
       } 

       int prefixSum = 0;

       for(int i= 0; i<nums.size(); i++){
        if (prefixSum == total - prefixSum - nums[i]){
            return i;
        }
        prefixSum += nums[i];
       }

       return -1;
    }
};