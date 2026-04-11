class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<int>> directions = {{0,1},{1,0},{0,-1},{-1,0}};

        vector<vector<int>> gridMax (rows, vector<int> (cols, INT_MAX));
        gridMax[0][0] = grid[0][0];
        vector<vector<bool>> visited (rows, vector<bool> (cols, false));

        priority_queue< vector<int>, vector<vector<int>> , greater<>> minHeap;
        minHeap.push({grid[0][0],0,0});

        while(!minHeap.empty()){
            auto minElev = minHeap.top();
            minHeap.pop();
            int time = minElev[0];
            int row = minElev[1];
            int col = minElev[2];

            visited[row][col] = true;

            if(row == rows-1 && col == cols-1){
                return time;
            }

            for(int i=0; i<4; i++){
                int nr = row + directions[i][0];
                int nc = col + directions[i][1];

                if(nr<0 || nc<0 || nr >=rows || nc>= cols || visited[nr][nc]){
                    continue;
                }

                int newtime = max(time, grid[nr][nc]);

                if(newtime<gridMax[nr][nc]){
                    gridMax[nr][nc] = time;
                    minHeap.push({newtime, nr, nc});
                }
            }
        }
        return 0;
    }
};
