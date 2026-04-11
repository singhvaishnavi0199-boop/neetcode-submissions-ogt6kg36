class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";
        int l =0;
        int r =0;
        int n =word1.size();
        int m = word2.size();
        while(l<n && r<m){
            ans+=word1[l];
            ans+=word2[r];
            l++;
            r++;
        }
        if (l== n){
            ans+=word2.substr(r);
        }
        if (r==m){
            ans+=word1.substr(l);
        }
        return ans;
    }
};