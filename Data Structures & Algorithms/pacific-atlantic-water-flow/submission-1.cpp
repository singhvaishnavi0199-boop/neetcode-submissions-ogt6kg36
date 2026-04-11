class Solution {
public:
    vector<vector<int>> directions = {{0,1},{1,0},{0,-1}, {-1,0}};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<int>> ans;
        vector<vector<bool>> pac(rows, vector<bool> (cols, false));
        vector<vector<bool>> atl(rows, vector<bool> (cols, false));

        for(int r=0; r<rows; r++){
            dfs(r, 0, pac, heights);
            dfs(r, cols-1, atl, heights);
        }

        for(int c=0; c<cols; c++){
            dfs(0,c, pac, heights);
            dfs(rows-1,c, atl, heights);
        }

        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if (pac[i][j] && atl[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }

    void dfs(int r, int c, vector<vector<bool>>&ocean , vector<vector<int>>& heights){
        if(ocean[r][c]){
            return;
        }
        ocean[r][c] = true;

        for(int i=0; i<directions.size(); i++ ){
            int nr = r + directions[i][0];
            int nc = c + directions[i][1];

            if(nr>=0 && nc>=0 && nr<heights.size() && nc<heights[0].size() && heights[r][c]<= heights[nr][nc]){
                dfs(nr,nc,ocean,heights);
            }
        }
        return;
    }
};

/*
 p
    [4,2,7,3,4],
p   [7,4,6,4,7], a
    [6,3,5,3,6]
    a
*/