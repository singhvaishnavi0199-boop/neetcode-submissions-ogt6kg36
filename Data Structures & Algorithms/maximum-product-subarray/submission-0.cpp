class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currMax = 1;
        int currMin = 1;
        int globalMax = INT_MIN;

        for(int i=0; i<nums.size(); i++){
            int num = nums[i];

            if (num==0){
                currMax = 1;
                currMin = 1;
                globalMax = max(globalMax, num);
                continue;
            }

            int tempMax = max({num, currMax * num , currMin* num});
            int tempMin = min({num, currMax * num , currMin* num});

            currMax = tempMax;
            currMin = tempMin;

            globalMax = max(globalMax, currMax);

        }
        return globalMax;
    }
};
