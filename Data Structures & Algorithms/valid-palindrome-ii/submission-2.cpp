#include <bits/stdc++.h>
class Solution {
public:
    bool validPalindrome(string s) {
        int l = 0;
        int r = s.size()-1;
        while (l<r){
            if (s[l] != s[r]){
                return isPalindrome(s.substr(0,r) + s.substr(r+1)) || isPalindrome(s.substr(0,l) + s.substr(l+1)) ;
            }
            l++;
            r--;
        }
        return true;
    }

private:
    bool isPalindrome (string s){
        int l = 0;
        int r = s.size()-1;
        while(l<r){
            if(s[l]!=s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};