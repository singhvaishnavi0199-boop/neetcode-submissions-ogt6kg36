#include <map>
class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> mp;
        for (int i = 0; i<s.length() ; i++){
            mp[s[i]] = mp[s[i]] + 1;
        }
        for (int i = 0; i< t.length() ; i++){
            if (mp.count(t[i]) == 0){
                return false;
            }
            mp[t[i]] = mp[t[i]] - 1;
        }

        for (auto &it : mp) {
            if (it.second != 0){
                return false;
            }
        }

        return true;
    }
};
