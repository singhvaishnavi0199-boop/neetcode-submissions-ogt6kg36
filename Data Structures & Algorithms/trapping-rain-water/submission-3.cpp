class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l = 0;
        int r = n-1;
        int leftMax = height[0];
        int rightMax = height[n-1];
        int result = 0;

        while(l<r){
            if (leftMax < rightMax){
                l++;
                int water = leftMax - height[l];
                if (water> 0){
                    result += water;
                }
                leftMax = max(height[l], leftMax);
            }else{
                r--;
                int water = rightMax - height[r];
                if (water> 0){
                    result += water;
                }
                rightMax = max(height[r], rightMax);
            }
        }
        return result;
    }
};
