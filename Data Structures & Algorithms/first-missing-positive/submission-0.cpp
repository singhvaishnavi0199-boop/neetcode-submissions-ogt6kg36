class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // smallest positive integer would be between 1 to n+1
        int n = nums.size();
        for (int i =0 ; i<n ; i++){
            while ( nums[i] > 0 && nums[i] < n+1 && nums[i]!= nums[nums[i]- 1]){
                swap(nums[i], nums[nums[i]- 1]);
            } 
        }

        for(int i = 0 ; i< n; i++){
            if (nums[i] != i+1){
                return i+1;
            }
        }
        return n+1;
    }
};