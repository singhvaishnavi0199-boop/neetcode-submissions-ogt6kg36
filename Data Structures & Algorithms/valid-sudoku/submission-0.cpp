class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
       unordered_map <int, unordered_set<int>> rowMap;
       unordered_map <int, unordered_set<int>> colMap;
       map <pair<int,int>, unordered_set<int>> gridMap;

       for(int i =0; i<board.size(); i++){
        for(int j =0; j<board[i].size(); j++){
            if (board[i][j] == '.'){
                continue;
            }
            int no = board[i][j] - '0';
            if (rowMap[i].find(no) != rowMap[i].end()){
                return false;
            }else{
                rowMap[i].insert(no);
            }

            if (colMap[j].find(no) != colMap[j].end()){
                return false;
            }else{
                colMap[j].insert(no);
            }

            int gridi = i/3;
            int gridj = j/3;

            if (gridMap[{gridi, gridj}].find(no) != gridMap[{gridi, gridj}].end()){
                return false;
            }else{
                gridMap[{gridi, gridj}].insert(no);
            }
         }
       }
       return true;
    }
};
