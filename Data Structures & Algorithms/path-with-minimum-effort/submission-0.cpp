class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();

        vector<vector<int>> dijmap(rows, vector<int>(cols, INT_MAX));
        dijmap[0][0] = 0;

        priority_queue < vector<int> , vector<vector<int>> , greater<>> minHeap;
        minHeap.push({0,0,0}); // currentEffort, row, col

        vector<vector<int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};

        while(!minHeap.empty()){
            auto curr = minHeap.top();
            int currEffort = curr[0];
            int row = curr[1];
            int col = curr[2];

            if (row == rows-1 && col == cols-1){
                return currEffort;
            }

            minHeap.pop();

            for(int i=0;i<4; i++){
                int newRow = row + directions[i][0];
                int newCol = col + directions[i][1];

                if (newRow <0 || newCol <0 || newRow >= rows || newCol >= cols){
                    continue;
                }

                int diff = max (currEffort, abs(heights[row][col]- heights[newRow][newCol]));

                if (diff < dijmap[newRow][newCol]){
                    dijmap[newRow][newCol] = diff;
                    minHeap.push({diff, newRow, newCol});
                }
            }

        }

        //while heap is not empty
            // if heap top = r-1, c-1 , then return
            //currDiff = max (currDiff, abs(height diff))
            // if currDiff < currEffort (inifinity or already evaluated), then currDiff it is
        
    }
};