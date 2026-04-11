class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end());
        int r = 0;
        for (int i =0; i<weights.size(); i++){
            r += weights[i];
        }

        int res = r;

        while (l<=r){
            int m = l + (r-l)/2;
            if (canShip (weights, days, m)){
                res = min(res , m);
                r = m-1;
            }else{
                l = m+1;
            }
        }
        return res;
    }

private:
    bool canShip(vector<int>& weights,int days, int cap){
        int ship = 1;
        int currCap = cap;
        for (int i =0 ;i<weights.size(); i++){
            if (currCap - weights[i]< 0){
                ship++;
                if (ship > days){
                    return false;
                }
                currCap = cap;
            }
            currCap -= weights[i];
        }
        return true;
    }

};