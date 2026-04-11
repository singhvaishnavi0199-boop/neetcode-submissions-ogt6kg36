class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int total = 0;
        int n = piles.size();
        for(int i=0; i<n; i++){
            total += piles[i];
        }
        vector<vector<int>> memo (n, vector<int> (n, -1));
        int aliceScore = dp(0, piles.size()-1, piles, memo);
        return aliceScore > total - aliceScore;
    }

    int dp (int l, int r , vector<int> &piles , vector<vector<int>>& memo){
        if (l > r){
            memo[l][r] = 0;
            return memo[l][r];
        }

        if (memo[l][r] != -1){
            return memo[l][r];
        }

        memo[l][r] = 0;

        bool even = r + 1 - l;
        if (even) {
            // select l
            int poss1 = piles[l+1] > piles[r] ? piles[l] + dp (l+2, r, piles ,memo) : piles[l] + dp (l+1, r-1, piles, memo);
            // select r
            int poss2 = piles[l] > piles[r-1] ? piles[r] + dp (l+1, r-1, piles, memo) : piles[r] + dp (l, r-2, piles, memo);
            // max of both
            memo[l][r] = max (poss1, poss2);
        }else{
            memo[l][r] = 0;
        }

        return memo[l][r];
    }
};