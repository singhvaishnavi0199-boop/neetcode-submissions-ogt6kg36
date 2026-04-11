class Solution {
public:
    vector<vector<int>> dp;
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();

        if(n> m){
            return 0;
        }
        if (n == 0){
            return 1;
        }
        dp.assign(m+1, vector<int> (n+1,-1));
        return dfs(s, t, 0, 0);
    }

private:
    int dfs(string &s, string &t, int i, int j){
        if (j == t.size()){
            return 1; // reached end of t => 1 distinct sub sequence possible
        } 
        if (i == s.size()){
            return 0; // reached end of s before end of t => no distinct sub sequence possible
        } 

        if(dp[i][j] != -1){
            return dp[i][j]; // dp[i][j] represents no of distinct sub seq for s[i:] for t[j:]
        }

        int res = dfs(s, t, i+1, j); // not using ith element of s
        if (s[i] == t[j]){
            // res += dfs(s, t, i+1, j); // not using ith element of s
            res += dfs(s, t, i+1, j+1); // using ith element of s
        }
        // else{
        //     // res += dfs(s, t, i+1, j); // not using ith element of s
        // }
        dp[i][j] = res;
        return res;
    }
};
