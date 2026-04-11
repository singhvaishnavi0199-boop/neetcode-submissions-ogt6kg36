class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res = "";
        while(columnNumber > 0){
            columnNumber --;
            res += (columnNumber % 26) + 'A';
            cout<<"res "<<res<<endl;
            columnNumber = columnNumber / 26;
            cout<<"columnNumber "<<columnNumber<<endl;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};