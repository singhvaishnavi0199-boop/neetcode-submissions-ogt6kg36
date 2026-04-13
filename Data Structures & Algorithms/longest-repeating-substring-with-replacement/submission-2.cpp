class Solution {
private:
    unordered_map<char,int> mapCount;

    int mostFreqCharCount (unordered_map<char,int>& mapCount){
        // auto it = mapCount.begin();
        int ans = 0;
        for (auto &it : mapCount){
            ans = max (ans , it.second);
        }
        return ans;
    }
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int r = 0;
        int n = s.size();
        int res = 0;

        while(l <= r && r<n){
            cout << r <<" "<< l << endl;
            mapCount[s[r]]++;
            cout<< s[r] <<" "<<mapCount[s[r]]<<endl;
            int sizeOfWindow = r - l + 1;
            int mostFreq = mostFreqCharCount(mapCount);
            cout<< "mostFreq "<<mostFreq<<endl; 
            if (sizeOfWindow - mostFreq <= k){
                res = max (res, sizeOfWindow);
                r++;
            }else{
                mapCount[s[l]]--;
                r++;
                l++;
            }
        }
        return res;
        
    }
};

/*
l= 0
r =0

map
A - 1

sizeOfWindow - mostFreq >=k 

res = sizeOfWindow

*/