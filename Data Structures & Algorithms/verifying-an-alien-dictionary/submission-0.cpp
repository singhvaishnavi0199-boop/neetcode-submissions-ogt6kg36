class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> mp;
        for (int i= 0;i<order.length();i++){
            mp[order[i]]= i;
        }

        for (int i=0;i<words.size()-1;i++){
            string word1 = words[i];
            string word2 = words[i+1];

            int j = 0;
            while (j<word1.length() && j<word2.length()){
                if (mp[word1[j]] > mp[word2[j]]){
                    return false;
                }

                if (mp[word1[j]] < mp[word2[j]]){
                    break;
                }

                j++;
            }

            if (j == word2.length() && j<word1.length()){
                return false;
            }
        }

        return true;
    }
};