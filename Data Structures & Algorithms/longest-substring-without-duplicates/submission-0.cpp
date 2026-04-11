class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> sub;
        int l = 0;
        int res = 0;
        for (int r=0 ; r<s.size(); r++){
            while (sub.find(s[r])!=sub.end()){
                sub.erase(s[l]);
                l++;
            }
            sub.insert(s[r]);
            int length = r-l+1;
            res = max(res, length);
        }

        return res;
    }
};
