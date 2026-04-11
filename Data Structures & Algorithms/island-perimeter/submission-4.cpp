// class Solution {

// private:

//     vector<vector<int>> grid;
//     vector<vector<bool>> visited;
//     int rows, cols;

//     int dfs (int i, int j){
//         if (i<0 || j<0 || i>=rows || j>= cols || grid[i][j] == 0){
//             return 1;
//         }
//         if (visited[i][j]){
//             return 0;
//         }

//         visited[i][j] = true;
//         return dfs(i-1,j) + dfs(i+1, j) + dfs(i, j+1)+ dfs(i, j-1);
//     }


// public:
//     int islandPerimeter(vector<vector<int>>& grid) {
//         this -> grid = grid;
//         rows = grid.size();
//         cols = grid[0].size();

//         visited = vector<vector<bool>> (rows, vector<bool>(cols,false));
//         for (int i=0;i<rows;i++){
//             for (int j=0 ;j<cols; j++){
//                 if (grid[i][j] == 1){
//                     return dfs(i,j);
//                 }
//             }
//         }
//         return 0;
//     }
// };


class Solution{
    public :
        int islandPerimeter (vector<vector<int>> &grid){
            int rows = grid.size();
            int cols = grid[0].size();
            int res = 0;
            for (int i=0; i<rows; i++){
                for (int j=0; j<cols; j++){
                    if (grid[i][j] == 1){
                        res += (i-1<0 || grid[i-1][j]==0) ? 1:0;
                        res += (i+1>=rows || grid[i+1][j]==0) ? 1:0;
                        res += (j-1<0 || grid[i][j-1]==0) ? 1:0;
                        res += (j+1>=cols || grid[i][j+1]==0) ? 1:0;
                    }
                }
            }
            return res;
        }
};