class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> combine(int n, int k) {
        vector<int> curr;
        backtrack(n,curr,k,1);
        return result;
    }

    void backtrack(int n , vector<int> & curr, int k ,int i){
        if (i > n){
            if (curr.size() == k){
                result.push_back(curr);
            }
            return;
        }
        curr.push_back(i);
        backtrack(n, curr, k , i+1);

        curr.pop_back();
        backtrack(n, curr, k, i+1);
    }
};