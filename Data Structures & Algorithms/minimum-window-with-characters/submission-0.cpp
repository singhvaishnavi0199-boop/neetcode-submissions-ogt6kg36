class Solution {
public:
    string minWindow(string s, string t) {
        // res length = INT_MAX;
        int resLength = INT_MAX;
        string result = "";

        // map -> char,int all elem in t 
        unordered_map <char,int> mp;
        for(int i=0; i<t.size(); i++){
            mp[t[i]]++;
        }

        // window
        unordered_map<char,int> window;

        // no of elem in t = want
        // no of wanted elem in window = have
        int want = mp.size();
        int have = 0;


        // l = 0;
        // r = 0;
        int l = 0;
        for(int r = 0; r<s.size(); r++){
            char ele = s[r];
            window[ele]++;
            if (mp.count(ele) && (window[ele] == mp[ele])){
                have++;
            }
            while(want == have){
                int currLength = r - l +1;
                if (resLength > currLength){
                    resLength = currLength;
                    result = s.substr(l , currLength);
                }
                char startEle = s[l];
                window[startEle]--;
                if (mp.count(startEle) && window[startEle] < mp[startEle]){
                    have--;
                }
                l++;
            }

        }
        // add ele to window : if wanted ele , then have++;
        // if have = wanted
            // min of length of res , window length
        // move l till have == wanted
        // again move r , repeat the same.

        return result;

    }
};
