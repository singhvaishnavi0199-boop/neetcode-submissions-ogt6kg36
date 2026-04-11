class Solution {
public:
    vector<vector<int>> directions = {{0,1},{1,0},{0,-1},{-1,0}};
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<pair<int,int> ,int>> q;
        int minute = 0;
        int freshFruits = 0;

        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if (grid[i][j]==2){
                    q.push({{i,j},minute});
                }
                if(grid[i][j]==1){
                    freshFruits++;
                }
            }
        }
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int min = q.front().second;
            q.pop();
            minute = min;


            for(int i=0; i<directions.size(); i++){
                int nr = r + directions[i][0];
                int nc = c + directions[i][1];

                if(nr>=0 && nc>=0 && nr< rows && nc< cols && grid[nr][nc]==1){
                    freshFruits--;
                    grid[nr][nc]= 2;
                    q.push({{nr,nc}, min+1});
                }
            }
        }

        if (freshFruits == 0){
            return minute;
        }else{
            return -1;
        }
    }
};
