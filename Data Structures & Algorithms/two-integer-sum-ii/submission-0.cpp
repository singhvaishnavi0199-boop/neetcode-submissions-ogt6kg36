class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size() - 1;
        vector <int> ans;
        while (l<numbers.size() && r>0 && l<r){
            if (numbers[l] + numbers[r] > target){
                r--;
            }else if (numbers[l] + numbers[r] < target){
                l++;
            }else{
                ans.push_back(l+1);
                ans.push_back(r+1);
                return ans;
            }
        }
    }
};
