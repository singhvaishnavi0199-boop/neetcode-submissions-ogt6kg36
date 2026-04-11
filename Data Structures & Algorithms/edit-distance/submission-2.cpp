class Solution {
public:
    vector<vector<int>> dp;
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        dp.assign(n+1, vector<int> (m+1, -1));
        return dfs(word1, word2 , 0 , 0); // return dp[0][0] => from 0th index of word 1 
                                        // and 0th index of word2 , how many ways to edit distance.
        
    }

private:
    int dfs(const string& word1, const string& word2, int i , int j){
        if (i>= word1.size() ){
            return word2.size() - j;
        }

        if (j>= word2.size()){
            return word1.size() - i;
        }

        if (dp[i][j] != -1){
            return dp[i][j];
        }

        int res = 0;

        if (word1[i] == word2[j]){
            res = dfs(word1, word2, i+1, j+1);
        }else{
            int insert = dfs(word1, word2, i+1, j); 
            int add = dfs(word1, word2, i, j+1); 
            int replace = dfs(word1, word2, i+1, j+1); 
            res = 1 + min (min (insert, add), replace);
        }

        dp[i][j] = res;
        return dp[i][j];
    }
};

// if word1[i] == word2[j] {
//.  return result for word1, word2 , i+1, j+1
//}

/*
if word1[i] != word2[j] 

result for word1, word2 ,  + 1
remove it - i+1 , j 
add word - i , j+1
replace - i +1, j+1
*/
