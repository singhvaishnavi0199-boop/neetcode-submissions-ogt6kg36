// top down approach

class Solution {
public:
    vector<vector<int>> dp;
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        dp.assign(n+1, vector<int> (m+1, -1));
        return dfs(text1, text2, 0, 0);
    }

private:
    int dfs(string &text1, string &text2, int i, int j){
        if (i >= text1.size() || j >= text2.size()){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int res = 0;
        if(text1[i]==text2[j]){
            res = 1+ dfs(text1, text2, i+1, j+1);
        }else{
            res = max( dfs(text1, text2, i, j+1) , dfs(text1, text2, i+1, j));
        }

        dp[i][j] = res;
        return res;
    }
};
