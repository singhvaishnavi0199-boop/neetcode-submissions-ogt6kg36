//dfs
class Solution {
public:
    vector<vector<bool>> visited;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        visited.assign(rows, vector<bool> (cols, false));
        for(int i=0; i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]== 1){
                    int area = dfs(i,j,grid);
                    maxArea = max(area, maxArea);
                }
            }
        }

        return maxArea;
    }

    int dfs(int i,int j, vector<vector<int>>& grid){
        if (i <0 || j<0 || i>=grid.size() || j>= grid[0].size() || grid[i][j]==0){
            return 0;
        }

        if(visited[i][j]){
            return 0;
        }

        visited[i][j] = true;

        return 1 + dfs(i+1, j, grid) + dfs(i,j+1, grid) + dfs(i-1, j, grid) + dfs(i,j-1,grid);
    }
};
