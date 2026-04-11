class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int l = 0;
        deque<int> dq;
        vector<int> result;
        int n = nums.size();

        for(int r = 0; r< k ; r++){
            if (dq.empty()){
                dq.push_back(r);
            }else{
                if (nums[r] > nums[dq.front()]){
                dq.push_front(r);
                }else{
                    while(!dq.empty() && nums[dq.back()] < nums[r]){
                        dq.pop_back();
                    }
                    dq.push_back(r);
                }
            }
        }
        int r = k-1;

        while(r<n){
            result.push_back(nums[dq.front()]);
            l++;
            r++;

            while(!dq.empty() && dq.front() < l){
                dq.pop_front();
            }
            if (nums[r] > nums[dq.front()]){
                dq.push_front(r);
            }else{
                while(!dq.empty() && nums[dq.back()] < nums[r]){
                    dq.pop_back();
                }
                dq.push_back(r);
            }
        }

        return result;
    }
};
