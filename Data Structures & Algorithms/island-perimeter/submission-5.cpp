class Solution {
public:
    vector<vector<bool>> visited;
    int islandPerimeter(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        visited.assign(rows, vector<bool> (cols, false));

        for(int i=0; i<rows;i++){
            for(int j=0; j<cols; j++){
                if(grid[i][j]==1){
                    return dfs(i,j,grid);
                }
            }
        }
        return 0;
    }

    int dfs(int r, int c, vector<vector<int>>& grid){
        if (r<0 || c<0 || r==grid.size() || c== grid[0].size() || grid[r][c]==0){
            return 1;
        }

        if(visited[r][c]){
            return 0;
        }

        visited[r][c]= true;

        return dfs(r,c+1, grid) + dfs(r+1, c, grid) + dfs(r-1,c, grid) + dfs(r,c-1,grid);
    }
};