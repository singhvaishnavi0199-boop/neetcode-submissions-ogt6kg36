class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 0;
        unordered_map<char, int> freq;
        int l = 0;
        int maxFreq = 0;

        for(int r = 0; r<s.length() ; r++){
            freq[s[r]]++;
            maxFreq = max (maxFreq, freq[s[r]]);
            // window size - maxFreq > k
            while((r-l+1) - maxFreq > k){
                freq[s[l]]--;
                // we don't update the max window size, we might allow invalid window of
                // same size but not larger invalid window
                l++;
            }

            res = max(res, (r-l+1));

        }

        return res;
    }
};
