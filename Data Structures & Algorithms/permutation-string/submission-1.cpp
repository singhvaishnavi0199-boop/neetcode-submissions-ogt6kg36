class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s2.size()<s1.size()){
            return false;
        }
        vector<int> s1Count(26,0);
        vector<int> s2Count(26,0);
        for (int i=0;i<s1.length();i++){
            s1Count[s1[i]-'a']++;
            s2Count[s2[i]-'a']++;
        }

        int matches = 0;
        for(int i=0;i<26;i++){
            if(s1Count[i]==s2Count[i]){
                matches++;
            }
        }
        
        int l =0;
        for(int r= s1.size(); r<s2.size(); r++){
            if (matches == 26){
                return true;
            }

            //outgoing
            int index = s2[l]-'a';
            s2Count[index]--;
            if (s1Count[index]==s2Count[index]){
                matches++;
            }else if (s1Count[index] - 1 == s2Count[index]){
                matches--;
            }
            l++;

            //incoming
            index = s2[r]-'a';
            s2Count[index]++;
            if (s1Count[index]==s2Count[index]){
                matches++;
            }else if (s1Count[index] + 1 == s2Count[index]){
                matches--;
            }
        }

        return matches==26;
    }
};
