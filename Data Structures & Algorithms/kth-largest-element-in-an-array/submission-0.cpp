class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue <int, vector<int> , greater<int>> minpq;
        for (int i =0; i< nums.size(); i++){
            minpq.push(nums[i]);
            if (minpq.size()>k){
                minpq.pop();
            }
        }
        return minpq.top();
    }
};
