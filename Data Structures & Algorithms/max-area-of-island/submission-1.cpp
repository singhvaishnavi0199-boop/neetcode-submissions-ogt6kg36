// === dfs ===

// class Solution {
// public:
//     int maxAreaOfIsland(vector<vector<int>>& grid) {
//         int rows = grid.size();
//         int cols = grid[0].size();
//         int result = 0; // max area

//         for(int r =0 ; r<rows ; r++){
//             for(int c=0; c<cols; c++){
//                 if (grid[r][c]==1){
//                     int area = dfs(grid,r,c);
//                     result = max(area, result);
//                 }
//             }
//         }

//         return result;
//     }

//     int dfs(vector<vector<int>>& grid , int r, int c){
//         if (r<0 || c<0 || r>= grid.size() || c>= grid[0].size() || grid[r][c]==0){
//             return 0;
//         }
//         grid[r][c] =0 ;
//         int area = 1;

//         area+= dfs(grid, r-1, c);
//         area+= dfs(grid, r, c-1);
//         area+= dfs(grid, r+1, c);
//         area+= dfs(grid, r, c+1);

//         return area;

//     }
// };


// === bfs ====


class Solution{

int directions[4][2] = {{0,1}, {1,0}, {-1,0}, {0,-1}};
public:
    int maxAreaOfIsland(vector<vector<int>>& grid){
        int rows = grid.size();
        int cols = grid[0].size();
        int result = 0;

        for (int r=0; r<rows; r++){
            for(int c=0; c<cols; c++){
                if(grid[r][c]==1){
                    int area = bfs(grid, r, c);
                    result = max(area, result);
                }
            }
        }

        return result;
    }

    int bfs(vector<vector<int>>& grid , int r, int c){
        int area = 1;
        queue<pair<int, int>> q;
        q.push({r,c});
        grid[r][c]=0;

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            for(int i =0; i<4; i++){
                int nextRow = row + directions[i][0];
                int nextCol = col + directions[i][1];

                if(nextRow >= 0 && nextCol >=0 && nextRow<grid.size() && nextCol< grid[0].size() && grid[nextRow][nextCol]==1){
                    area++;
                    q.push({nextRow,nextCol});
                    grid[nextRow][nextCol]= 0;
                }
            }
            q.pop();
        }
        return area;
    }
};
