class Solution {
public:
    int directions[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int minutes = 0;
        int freshFruits = 0;

        queue<pair<int,int>> q;
        for(int r =0; r<rows; r++){
            for(int c=0; c<cols; c++){
                if(grid[r][c]==1){
                    freshFruits++;
                }
                if(grid[r][c]==2){
                    q.push({r,c});
                }
            }
        }

        while(!q.empty() && freshFruits > 0){
            int length = q.size();

            for (int k =0; k<length; k++){
                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                for(int i=0;i<4;i++){
                    int nr = row + directions[i][0];
                    int nc = col + directions[i][1];
                    if(nr>=0 && nc>=0 && nr<grid.size() && nc<grid[0].size() && grid[nr][nc]==1){
                        grid[nr][nc]=2;
                        q.push({nr,nc});
                        freshFruits--;
                    }
                }
            }
            minutes++;
        }

        if (freshFruits == 0){
            return minutes;
        }else{
            return -1;
        }
    }
};
