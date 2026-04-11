class Solution {
public:
    void reverseRange(vector<int>& arr , int l , int r){
        // int l = 0;
        // int r = arr.size()-1;
        while(l<r){
            int temp = arr[l];
            arr[l] = arr[r];
            arr[r] = temp;
            l++;
            r--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        k = k% nums.size(); // important in reversal problem
        reverseRange(nums, 0, nums.size()-1);
        reverseRange(nums, 0, k-1);
        reverseRange(nums, k, nums.size()-1);
        return;
    }
};