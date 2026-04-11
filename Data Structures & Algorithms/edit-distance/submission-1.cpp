class Solution {
public:
    vector<vector<int>> dp;
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        dp.assign(n+1, vector<int> (m+1, -1));
        return dfs(word1, word2, 0, 0);
    }

private:
    int dfs(string &word1, string &word2, int i , int j){
        if(j == word2.size()){
            return word1.size()-i;
        }
        if(i == word1.size()){
            return word2.size()-j;
        }
        if (dp[i][j] != -1){
            return dp[i][j];
        }

        int res = 0;
        if (word1[i] == word2[j]){
            res = dfs(word1, word2, i+1, j+1);
        }else{
            int insertOp =dfs(word1, word2, i, j+1);
            int deleteOp = dfs(word1, word2, i+1, j);
            int replaceOp = dfs(word1, word2, i+1, j+1);
            res =  1+ min (insertOp , min(deleteOp,replaceOp));
        }

        dp[i][j] = res;
        return res;
    }
};
