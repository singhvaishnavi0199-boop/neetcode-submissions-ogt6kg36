class Solution {

private:
    bool canSplit(vector<int>& nums, int k, int target){
        int subArray = 1;
        int currSum = 0;
        for(int i = 0; i<nums.size(); i++){
            currSum += nums[i];
            if (currSum > target){
                subArray++;
                if (subArray > k){
                    return false;
                }
                currSum = nums[i];
            }
        }
        return true;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int l = *max_element(nums.begin(), nums.end());
        int r = accumulate(nums.begin(), nums.end(), 0);
        int res = r; //max largest sum of the sub array 

        while(l<= r){
            int mid = l + (r-l)/2;
            if (canSplit(nums, k , mid)){
                res = mid;
                r = mid -1;
            }else{
                l = mid +1;
            }
        }
        return res;
    }
};