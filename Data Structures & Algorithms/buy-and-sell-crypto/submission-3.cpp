class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0;
        int r = 1;
        int maxProfit =0;

        while(r<prices.size()){
            if (prices[l]>prices[r]){
                l = r;
                r++;
            }else {
                maxProfit = max (maxProfit, prices[r]-prices[l]);
                r++;
            }
        }

        return maxProfit;
    }
};
