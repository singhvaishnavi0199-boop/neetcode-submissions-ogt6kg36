class Solution {
private:
    vector<vector<int>> directions = {{0,1},{1,0}, {-1,0}, {0,-1}};
public:
    int swimInWater(vector<vector<int>>& grid) {
        
        // bfs on minHeap

        /*
        time lapsed, {r, c}
        visited
        if neigh value is smaller , than timeLapsed will not increase
        but the neigh small valued cells will be marked visited
        once r-1, c- 1 is visited, we return the time lapsed
        */

        int timeLapsed = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<bool>> visited(rows, vector<bool> (cols, false));

        priority_queue< pair<int, pair<int,int>> , vector<pair<int, pair<int,int>>> , greater<>> minHeap;
        minHeap.push({grid[0][0], {0,0}});

        while(!minHeap.empty()){
            auto node = minHeap.top();
            int time = node.first;
            int r = node.second.first;
            int c = node.second.second;
            cout<< time <<" "<< r << " "<<c<<endl;

            minHeap.pop();

            timeLapsed = max (timeLapsed , time);
            if (r == rows-1 && c == cols-1){
                return timeLapsed;
            }

            if(visited[r][c] == true){
                continue;
            }

            visited[r][c] = true;

            for(int i = 0; i<directions.size(); i++){
                int nr = r + directions[i][0];
                int nc = c + directions[i][1];
                
                if (nr <0 || nc<0 || nr >= rows || nc >= cols || visited[nr][nc]== true){
                    continue;
                }
                cout<< "neigh "<<grid[nr][nc] <<" "<<nr<<" "<<nc<<endl;


                minHeap.push({grid[nr][nc] , {nr,nc}});
                cout<< "pushed "<<grid[nr][nc] <<" "<<nr<<" "<<nc<<endl;
            }
        }
        return 0;
    }
};
