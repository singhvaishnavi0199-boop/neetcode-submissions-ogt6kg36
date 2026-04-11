class Solution {
public:
    vector<vector<bool>> visited;
    int numIslands(vector<vector<char>>& grid) {
        int result = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        visited.assign(rows, vector<bool> (cols, false));

        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(grid[i][j]== '1' && visited[i][j]==false){
                    dfs(i,j, grid);
                    result++;
                }
            }
        }

        return result;
    }

    void dfs(int i, int j, vector<vector<char>>& grid){
        if(i<0 || j<0 || i== grid.size() || j == grid[0].size() || grid[i][j]=='0'){
            return;
        }

        if(visited[i][j]){
            return;
        }

        visited[i][j] = true;

        dfs(i+1,j,grid);
        dfs(i,j+1,grid);
        dfs(i-1,j,grid);
        dfs(i,j-1,grid);
        return;
    }
};
