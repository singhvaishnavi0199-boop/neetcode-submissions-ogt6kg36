class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result;
        while(columnNumber > 0){
            columnNumber -- ;
            int offset = columnNumber % 26;
            result += 'A' + offset;
            columnNumber = columnNumber / 26; 
        }
        reverse(result.begin(), result.end());
        return result;
    }
};