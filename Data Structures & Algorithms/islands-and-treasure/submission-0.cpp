class Solution {
public:
    int directions[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int,int>> q;
        for (int r=0;r<rows;r++){
            for(int c=0;c<cols;c++){
                if(grid[r][c]==0){
                    q.push({r,c});
                }
            }
        }

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int nextRow = row + directions[i][0];
                int nextCol = col + directions[i][1];

                if (nextRow >=0 && nextCol >=0 && nextRow < grid.size() && nextCol <grid[0].size() && grid[nextRow][nextCol]==INT_MAX){
                    grid[nextRow][nextCol] = grid[row][col] + 1;
                    q.push({nextRow,nextCol});
                }
            }
        }
    }
};
