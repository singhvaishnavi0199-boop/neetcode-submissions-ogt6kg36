class Solution {
public:
    int trap(vector<int>& height) {
        int result = 0;
        int n = height.size();
        vector<int> leftMax(n, 0);
        vector<int> rightMax(n, 0);
        leftMax[0] = height[0];
        rightMax[n-1] = height[n-1]; 

        for(int i = 1; i<n; i++){
            leftMax[i] = max(leftMax[i-1], height[i-1]);
        }

        for(int i = n-2; i >= 0; i--){
            rightMax[i] = max(rightMax[i+1], height[i+1]);
        }

        for(int i =0;  i<n; i++){
            int water = min(leftMax[i], rightMax[i]) - height[i];
            if (water > 0){
                result += water;
            }
        }

        return result;

    }
};

/*
water stored at any given index =

min (tallest bar on the left, tallest bar on the right) - height of the bar
*/
