class Solution {
public:
    vector<vector<bool>> visited;
    vector<vector<int>> directions = {{0,1},{1,0},{0,-1},{-1,0}};
    int numIslands(vector<vector<char>>& grid) {
        int result = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        visited.assign(rows, vector<bool> (cols, false));

        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(grid[i][j]=='1' && !visited[i][j]){
                    queue<pair<int,int>> q;

                    q.push({i,j});
                    while(!q.empty()){
                        auto[r,c] = q.front();
                        q.pop();
                        visited[r][c]= true;
                        for(int k=0; k<directions.size(); k++){
                            int nr = r + directions[k][0];
                            int nc = c + directions[k][1];
                            if(nr >= 0 && nc >=0 && nr < rows && nc < cols && !visited[nr][nc] && grid[r][c]=='1'){
                                q.push({nr,nc});
                            }
                        }
                    }
                    result++;
                }
            }
        }

        return result;
    }
};
