class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;

        int left = 0;
        int right = matrix[0].size()-1;
        int top = 0;
        int bottom = matrix.size()-1;

        while(left <= right && top <= bottom){

            // left to right on top
            for(int c = left ; c<=right ; c++){
                result.push_back(matrix[top][c]);
            }
            top++;

            // top to bottom on right
            for(int r = top ; r<=bottom ; r++){
                result.push_back(matrix[r][right]);
            }
            right--;

            // right to left on bottom
            if(top<=bottom){
                for(int c = right ; c >= left ; c--){
                    result.push_back(matrix[bottom][c]);
                }
                bottom--;
            }

            // bottom to top on left
            if (left<=right){
                for(int r = bottom; r >= top; r--){
                    result.push_back(matrix[r][left]);
                }
                left++;
            }

        //     int r = top;
        //     int c = left;
        //     while(c<= right){
        //         result.push_back(matrix[r][c]);
        //         c++;
        //     }
        //     c--;
        //     r++;

        //     while(r<= bottom){
        //         result.push_back(matrix[r][c]);
        //         r++;
        //     }
        //     r--;
        //     c--;

        //     while(c >= left){
        //         result.push_back(matrix[r][c]);
        //         c--;
        //     }
        //     c++;
        //     r--;

        //     while(r > top){
        //         result.push_back(matrix[r][c]);
        //         r--;
        //     }
            
        //     left++;
        //     right--;
        //     bottom--;
        //     top++;
        }

        return result;
    }
};
