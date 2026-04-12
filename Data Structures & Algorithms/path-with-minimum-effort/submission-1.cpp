class Solution {
private:
    vector<vector<int>> directions = {{1,0}, {0,1}, {-1,0}, {0,-1}};
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        // int minEffort
        int minEffort = INT_MIN;
        // min Heap
        priority_queue < pair<int, pair<int,int>> , vector<pair<int, pair<int,int>>> , greater<>> minHeap;

        // visited
        vector<vector<bool>> visited(rows , vector<bool> (cols, false));

        minHeap.push({0 , {0,0}});

        while(!minHeap.empty()){
            auto node = minHeap.top();
            int effort = node.first;
            int r = node.second.first;
            int c = node.second.second;
            cout<< effort <<" "<< r <<" "<<c <<endl;

            if (r == rows-1 && c == cols -1){
                return max(minEffort , effort);
            }

            minHeap.pop();
            if (visited[r][c] == true) {
                continue;
            }
            visited[r][c] = true;

            minEffort = max(minEffort , effort);    
            cout<< "minEffort "<< minEffort<<endl;

            for (int i=0; i<directions.size(); i++){
                int nr = r + directions[i][0];
                int nc = c + directions[i][1];

                if (nr < 0 || nc < 0 || nr >= rows || nc >= cols || visited[nr][nc] == true){
                    continue;
                }

                int diff = abs (heights[r][c] - heights[nr][nc]);
                minHeap.push({diff, {nr,nc}});
            }
        }

        return minEffort;

    }
};