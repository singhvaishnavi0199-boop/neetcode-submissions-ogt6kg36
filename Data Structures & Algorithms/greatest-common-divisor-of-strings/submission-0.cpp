class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int l1 = str1.size();
        int l2 = str2.size();
        string small = l1<l2 ? str1 : str2;
        int n = small.size();

        for(int i = n ; i > 0 ; i--){
            if (l1 % i != 0 || l2 % i != 0){
                continue;
            }else{
                string curr = small.substr(0, i);
                string new1 , new2;
                while(new1.size()!= l1){
                    new1 += curr;
                }
                while(new2.size() != l2){
                    new2+= curr;
                }

                if (str1 == new1 && str2 == new2){
                    return curr;
                }
            }
        }
        return "";
    }
};