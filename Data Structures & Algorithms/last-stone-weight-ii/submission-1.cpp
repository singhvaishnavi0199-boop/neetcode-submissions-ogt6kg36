class Solution {

vector<vector<int>> dp; // outside means private : can be used inside the class
public:
    int lastStoneWeightII(vector<int>& stones) {
        int stoneSum = 0;
        for(int i=0; i<stones.size(); i++){
            stoneSum += stones[i];
        }

        int target = (stoneSum + 1)/2 ;
        int n = stones.size();

        dp = vector<vector<int>>(n, vector<int> (target+1, -1));
        return dfs(0,0,target,stoneSum, stones);
    }

    int dfs(int i , int total , int target , int stoneSum , vector<int>& stones){
        
        if(total >= target || i == stones.size()){
            return abs(total - (stoneSum - total));
        }

        if (dp[i][total] != -1){
            return dp[i][total];
        }

        dp[i][total] = min (dfs(i+1, total+ stones[i], target , stoneSum , stones),
                            dfs(i+1, total, target, stoneSum, stones));
        
        return dp[i][total];
    }
};