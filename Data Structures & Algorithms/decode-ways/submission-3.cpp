class Solution {
public:
    vector<int> dp;
    int numDecodings(string s) {
        int n = s.size();
        dp.assign(n+1 , -1);
        return dfs(0,n,s);
    }

    int dfs(int i, int n , string &s){
        if (i<n && s[i]=='0'){
            return 0;
        }

        if(i == n){
            return 1;
        }

        if (dp[i] != -1){
            return dp[i];
        }

        dp[i] = dfs(i+1, n, s);
        if (i+1<n){
            int val = std::stoi(s.substr(i,2));
            if (val >= 10 && val <= 26){
                dp[i] += dfs(i+2, n, s);
            }
        }
        return dp[i];
    }
};
