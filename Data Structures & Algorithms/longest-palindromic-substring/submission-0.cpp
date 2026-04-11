class Solution {
public:
    string longestPalindrome(string s) {
        int startIdx = 0;
        int len = 0;
        int stLen = s.length();

        for(int i =0 ; i<stLen ; i++){

            //odd length
            int l = i;
            int r = i;

            while(l >= 0 && r< stLen && s[l]==s[r]){
                if (len < r-l+1){
                    len = r - l + 1;
                    startIdx = l;
                }
                l--;
                r++;
            }

            //even length
            l = i;
            r = i+1;
            while(l >= 0 && r< stLen && s[l]==s[r]){
                if (len < r-l+1){
                    len = r - l + 1;
                    startIdx = l;
                }
                l--;
                r++;
            }
        }

        return s.substr(startIdx, len);
    }
};
