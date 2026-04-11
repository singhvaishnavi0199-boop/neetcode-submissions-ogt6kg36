class Solution {
    int directions[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();

        for (int r =0 ; r<rows; r++){
            if (board[r][0]=='O'){
                dfs(r,0,board);
            }
            if (board[r][cols-1]=='O'){
                dfs(r,cols-1,board);
            }
        }

        for(int c=0;c<cols; c++){
            if (board[0][c]=='O'){
                dfs(0,c,board);
            }
            if (board[rows-1][c]=='O'){
                dfs(rows-1,c,board);
            }
        }

        for(int r=0;r<rows; r++){
            for(int c=0; c<cols; c++){
                if (board[r][c]=='O'){
                    board[r][c]= 'X';
                }
                if(board[r][c] == '#'){
                    board[r][c] = 'O';
                }
            }
        }
    }

private :
    void dfs(int r, int c, vector<vector<char>>& board){
        board[r][c]='#';

        for(int i=0;i<4;i++){
            int nr = r + directions[i][0];
            int nc = c + directions[i][1];

            if (nr>=0 && nc>=0 && nr<board.size() && nc<board[0].size() && board[nr][nc]=='O'){
                dfs(nr,nc,board);
            }
        }
    }
};
