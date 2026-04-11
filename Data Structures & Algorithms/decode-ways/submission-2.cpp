class Solution {
public:
    vector<int> dp; // dp[i] == no of ways to decode the string starting from index i
    int numDecodings(string s) {
        int n = s.size(); // 0,1,2 ...n-1
        dp.assign(n+1, -1);
        return dfs(0, n ,s);
    }

private:
    int dfs(int i, int n , string& s){
        if (i < n && s[i] == '0'){
            return 0;
        }

        if (i == n){
            dp[i] = 1;
            return dp[i];
        }

        if (dp[i] != -1){
            return dp[i];
        }
        
        dp[i] = dfs(i+1, n, s);
        if (i+1 < n ){
            int val = std::stoi(s.substr(i,2));
            if (val <= 26 && val >= 10){
                dp[i] += dfs(i+2, n, s);
            }
        }
        return dp[i];
    }
};
