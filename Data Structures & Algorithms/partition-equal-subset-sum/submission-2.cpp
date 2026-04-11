/*

if total sum is even -> Partition Equal Subset Sum is possible

i = 0 , sum = 0
from here can i reach the target iterating all the nums.

at each i , i have a choice select or not select 
i = 0, 
sum = 1, i = 1 || sum = 0 , i = 1
*/


// #include <bits.stdc++.h>
// using namespace std;

class Solution{
    private:
        vector<vector<int>> dp;

        bool dfs (int i, int sum, int target , vector<int> &nums){
            // base case
            if (sum == target){
                return true;
            }

            if (i >= nums.size() || sum> target){
                return false;
            }

            // check if already calculated
            if (dp[i][sum] != -1){
                return dp[i][sum];
            }

            // small calculation + smaller problem
            dp[i][sum] = dfs(i+1, sum + nums[i], target, nums) ||
                         dfs(i+1, sum, target, nums);

            return dp[i][sum];
        }
    public:
        bool canPartition(vector<int> &nums){
            int total = 0;
            int n = nums.size();
            for( const auto num : nums){
                total += num;
            }

            // total must be even
            if (total%2 !=0){
                return false;
            }

            // target
            int target = total/2;

            // dp initialisation
            //dp[i][sum] represents whether it’s possible to reach 
            //the target sum using elements from index i onward, 
            //given that the current accumulated sum is sum.
            dp.assign(n, vector<int> (target+1, -1));

            //call dfs and return dfs
            return dfs(0,0,target,nums);
        }

};


// int main(){
//     Solution s;
//     vector<int> nums = {1,2,3,4};
//     cout<<s.canPartition(nums);
//     return 0;
// }