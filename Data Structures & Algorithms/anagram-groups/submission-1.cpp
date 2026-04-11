#include <unordered_map>
#include <string>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> result;
        for (int i=0 ; i<strs.size() ; i++){
            vector<int> v(26, 0);
            for (int j=0; j<strs[i].size(); j++){
                v[strs[i][j]-'a']++;
            }
            string key = "";
            for (int j=0; j<26 ; j++){
                key += "#" + to_string(v[j]);
            }
            result[key].push_back(strs[i]);
        }
        vector<vector<string>> res;
        for(auto &it:result){
            res.push_back(it.second);
        }
        return res;
    }
};
