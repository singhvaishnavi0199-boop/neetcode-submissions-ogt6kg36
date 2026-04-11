// ------DFS-------
// class Solution {
// public:
//     int numIslands(vector<vector<char>>& grid) {
//         int rows = grid.size();
//         int cols = grid[0].size();
//         int islands = 0;
        
//         for (int r=0;r<rows;r++){
//             for (int c=0;c<cols;c++){
//                 if (grid[r][c]=='1'){
//                     dfs(grid, r,c);
//                     islands++;
//                 }
//             }
//         }

//         return islands;
//     }

//     void dfs(vector<vector<char>>& grid, int r , int c){
//         if (r<0 || c<0 || r>=grid.size() || c>=grid[0].size() || grid[r][c]=='0'){
//             return;
//         }
        
//         grid[r][c]= '0';
//         dfs(grid, r-1, c);
//         dfs(grid, r, c-1);
//         dfs(grid, r+1, c);
//         dfs(grid, r, c+1);
//     }
// };


// -----BFS-----

class Solution{

    int directions[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    public:
        int numIslands(vector<vector<char>>& grid){
            int rows = grid.size();
            int cols = grid[0].size();
            int islands = 0;

            for (int r =0; r<rows; r++){
                for (int c=0;c <cols; c++){
                    if (grid[r][c]=='1'){
                        bfs(grid,r,c);
                        islands++;
                    }
                }
            }
            return islands;
        }

        void bfs(vector<vector<char>>& grid , int r, int c){
            queue<pair<int,int>> q;
            grid[r][c]=0;
            q.push({r,c});

            while(!q.empty()){
                int row = q.front().first;
                int col = q.front().second;
                for (int i=0;i<4;i++){
                    int nextRow = row + directions[i][0];
                    int nextCol = col + directions[i][1];

                    if (nextRow>=0 && nextCol >=0 && nextRow<grid.size() && nextCol < grid[0].size() && grid[nextRow][nextCol]=='1'){
                        q.push({nextRow,nextCol});
                        grid[nextRow][nextCol]='0';
                    }
                }
                q.pop();
            }
        }
};
