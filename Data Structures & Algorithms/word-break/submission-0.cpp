class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> memo (s.length()+ 1, -1);

        // can i break the s staring at index = 0 using wordDict
        return dp(0, memo, s, wordDict);
    }

    bool dp(int i , vector<int> &memo, string s , vector<string> &wordDict){
        if (i == s.length()){
            memo[i] = true;
            return memo[i];
        }

        if (memo[i] != -1){
            return memo[i];
        }

        for(const auto &word: wordDict){
            if (i+ word.length() <= s.length() && s.substr(i, word.length())== word){
                if (dp(i+word.length(), memo, s, wordDict)){
                    memo[i] = true;
                    return memo[i];
                }
            }
        }

        memo[i] = false;
        return memo[i];
    }


};
