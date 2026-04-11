class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();
        vector<int> dp(n, -1);
        dp[n-1] = true;
        return dfs(0,minJump,maxJump,s, dp);
    }

    bool dfs (int i , int minJump, int maxJump , string s,vector<int>& dp ){
        if (i== s.length()-1){
            return dp[s.length()-1];
        }

        if(dp[i] != -1){
            return dp[i];
        }

        
        bool res = false;
        for(int j = i+ minJump ; j <= min(i + maxJump, (int)s.length() - 1) ; j++){
            if (s[j] == '0'){
                res = res || dfs(j, minJump, maxJump, s, dp);
            }
        }

        dp[i] = res;
        return dp[i];
        
    }
};