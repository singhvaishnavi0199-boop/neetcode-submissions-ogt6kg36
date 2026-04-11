class Solution {
public:
    bool canPartition(vector<int>& nums) {
       int total = 0;
       for (int i =0; i<nums.size(); i++){
        total += nums[i];
       }

       if (total%2!=0){
        return false;
       }

       int target = total/2;

       return dfs(0,0, nums, target);
    }

private:
    bool dfs(int i, int sum , vector<int>& nums , int target){
        if (i == nums.size() || sum > target){
            return false;
        }
        if (sum == target){
            return true;
        }
        return dfs(i+1, sum+nums[i] , nums, target) || dfs(i+1, sum , nums, target);

        // pick i
        // don't pick i
    }
};
