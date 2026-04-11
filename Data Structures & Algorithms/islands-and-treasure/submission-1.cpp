class Solution {
public:
    vector<vector<int>> directions = {{0,1},{1,0},{0,-1},{-1,0}};
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<pair<int,int>, int>> q;
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(grid[i][j]==0){
                    q.push({{i,j},0});
                }
            }
        }

        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int dist = q.front().second;

            q.pop();

            for(int i=0; i<directions.size(); i++){
                int nr = r + directions[i][0];
                int nc = c+ directions[i][1];

                if(nr>=0 && nc >=0 && nr<rows && nc< cols && grid[nr][nc]==INT_MAX){
                    grid[nr][nc] = dist+1;
                    q.push({{nr,nc},grid[nr][nc]});
                }
            }
        }
        return;
    }
};
