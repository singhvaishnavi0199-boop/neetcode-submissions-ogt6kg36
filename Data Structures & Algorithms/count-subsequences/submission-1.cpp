class Solution {
public:
    vector<vector<int>> dp;
    int numDistinct(string s, string t) {
       dp.assign(s.size()+1, vector<int> (t.size()+ 1, -1));
       return dfs(s, t, 0, 0); 
    }

private:
    int dfs(const string& s, const string& t , int i, int j){
        if (i== s.size() && j <t.size()){
            return 0;
        }

        if(j == t.size()){
            return 1;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int res = dfs(s,t, i+1, j);
        if(s[i]== t[j]){
            res += dfs(s,t,i+1, j+1);
        }
        dp[i][j] = res;
        return dp[i][j];
    }
};

/*

if (s[i]==t[j]){
i+1, j and i+1, j+1}

else 
i+1, j

if  j == t.size() => traverse the entire string, return 1

if i == s.size() and j < t.size() => return 0;

*/
