class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int l = 0; 
        int r = n-1;

        while(l<r){
            if (r-l+1 == k){
                return {arr.begin()+l, arr.begin()+r+1};
            }
            if (abs(arr[l]-x) <= abs(arr[r]-x)){
                r--;
            }else{
                l++;
            }
        }
    }
};