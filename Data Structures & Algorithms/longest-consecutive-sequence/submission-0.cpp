class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hashSet;
        for(int i = 0; i<nums.size(); i++){
            hashSet.insert(nums[i]);
        }

        int ans = 0;

        for(int i =0; i<nums.size(); i++){
            if (hashSet.find(nums[i]-1) == hashSet.end()){
                // element - 1 does not exist, hence this can be the starting element
                int currLength = 1;
                int currEle = nums[i];
                while(hashSet.find(currEle+1) != hashSet.end()){
                    currEle++;
                    currLength++;
                }
                ans = max (currLength, ans);
            }
        }

        return ans;
    }
};
