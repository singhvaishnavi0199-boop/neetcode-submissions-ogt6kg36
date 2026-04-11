class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size()==1){
            return nums[0];
        }
        vector<int> nums1 (nums.begin(), nums.end()-1);
        vector<int> nums2 (nums.begin()+1, nums.end());
        return max(helper(nums1) , helper(nums2));
    }

    int helper(vector<int>& money){
        int n = money.size();
        if (n == 1){
            return money[0];
        }

        if (n==2){
            return max(money[0], money[1]);
        }
        int ans = 0;
        int rob1 = money[0];
        int rob2 = max(money[0], money[1]);

        for(int i= 2; i<n ; i++){
            ans = max (rob1 + money[i] , rob2);
            rob1 = rob2;
            rob2 = ans;
        }

        return ans;
    }
};
