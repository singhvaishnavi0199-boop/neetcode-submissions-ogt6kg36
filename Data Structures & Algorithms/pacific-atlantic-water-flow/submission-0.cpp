class Solution {
    int directions[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<int>> result;

        vector<vector<bool>> pac (rows, vector<bool>(cols, false));
        vector<vector<bool>> atl (rows, vector<bool>(cols, false));

        for(int r=0 ; r<rows ; r++){
            dfs (r , 0 , pac, heights);
            dfs (r, cols-1, atl , heights);
        }

        for(int c=0; c<cols ; c++){
            dfs (0, c, pac, heights);
            dfs (rows-1, c, atl, heights);
        }

        for (int r =0; r<rows ; r++){
            for(int c=0; c<cols ; c++){
                if (pac[r][c] && atl[r][c]){
                    result.push_back({r,c});
                }
            }
        }

        return result;
    }

private:

    void dfs(int r, int c, vector<vector<bool>>& ocean ,vector<vector<int>>& heights ){
        ocean[r][c] = true;

        for(int i =0; i<4 ;i++){
            int nr = r + directions[i][0];
            int nc = c + directions[i][1];

            if (nr>=0 && nc>=0 && nr< heights.size() && nc<heights[0].size() && !ocean[nr][nc] && heights[r][c]<= heights[nr][nc]){
                dfs(nr,nc, ocean, heights);
            }
        }

    }
};
