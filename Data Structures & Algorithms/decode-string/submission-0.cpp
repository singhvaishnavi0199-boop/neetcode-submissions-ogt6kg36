class Solution {
public:
    string decodeString(string s) {
        stack <string> st1;
        stack <int> st2;
        string curr = "";
        int k = 0;

        for(int i = 0; i<s.size(); i++){
            if (isdigit(s[i])){
                k = k * 10 + (s[i] - '0');
            }else if (s[i] == '['){
                st1.push(curr);
                st2.push(k);
                curr = "";
                k = 0;
            }else if (s[i] == ']'){
                string temp = curr;
                curr = st1.top();
                st1.pop();
                int count = st2.top();
                st2.pop();
                for(int j = 0; j<count ; j++){
                    curr += temp;
                }
            }else{
                curr += s[i];
            }
        }
        return curr;
    }
};