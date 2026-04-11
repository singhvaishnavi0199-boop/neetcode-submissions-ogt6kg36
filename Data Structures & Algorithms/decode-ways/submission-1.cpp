class Solution {
public:
    int numDecodings(string s) {
        vector<int> memo (s.size() , -1);
        return dp(0, memo , s);
    }

    int dp(int i, vector<int> &memo , string &s){
        if (s[i] == '0'){
            return 0; // no valid case can exist if starting position is 0
        }

        if (i == s.size()){
            return 1; // i > last index which implies we have gone through all indices ,
            // hence 1 valid path
        }

        if (memo[i] != -1){
            return memo[i]; // if already computed value
        }

        int res = dp(i+1, memo , s); // compute the result

        if (s[i] == '1' || (s[i]== '2' && s[i+1]-'0' < 7)){
            res += dp(i+2 , memo , s);
        }

        memo[i] = res; // store it in memo
        return memo[i]; // return memo value for the index
    }
};
