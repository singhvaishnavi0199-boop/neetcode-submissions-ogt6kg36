class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int total = 0;
        for(int i=0; i<piles.size(); i++){
            total += piles[i];
        }

        int aliceScore = dfs(0, piles.size()-1, piles);
        return aliceScore > total - aliceScore;
    }

    int dfs (int l, int r , vector<int> &piles){
        if (l > r){
            return 0;
        }

        bool even = r + 1 - l;
        int res = 0;
        if (even) {
            // select l
            int poss1 = piles[l+1] > piles[r] ? piles[l] + dfs (l+2, r, piles) : piles[l] + dfs (l+1, r-1, piles);
            // select r
            int poss2 = piles[l] > piles[r-1] ? piles[r] + dfs (l+1, r-1, piles) : piles[r] + dfs (l, r-2, piles);
            // max of both
            return max (poss1, poss2);
        }else{
            return 0;
        }
    }
};