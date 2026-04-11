class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        long long val = 0;
        int multiplier = 1;
        for(int i= n-1; i >= 0 ;i--){
            val += (long long)digits[i] * multiplier;
            multiplier *= 10;
        }
        val++;

        vector<int> res;
        while(val > 0){
            int digit = val % 10;
            val = val / 10; 
            res.push_back(digit);
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
