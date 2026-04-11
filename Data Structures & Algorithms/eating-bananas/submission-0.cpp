class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l =1;
        int r = *max_element(piles.begin(), piles.end());
        int res = r;

        while (l<=r){
            int k = l + (r-l)/2;
            int hours = 0;
            for (int i =0; i<piles.size(); i++){
                hours += ceil(static_cast<double>(piles[i])/k);
            }
            if (hours > h){
                l = k+1;
            }else{
                res= k;
                r = k-1;
            }
        }
        return res;
    }
};
