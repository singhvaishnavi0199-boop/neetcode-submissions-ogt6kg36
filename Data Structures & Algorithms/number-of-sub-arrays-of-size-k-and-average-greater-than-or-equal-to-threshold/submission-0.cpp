class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int res = 0;
        if (arr.size()<k){
            return 0;
        }
        int currSum = 0;
        for(int i = 0; i<k ; i++){
            currSum += arr[i];
        }
        int l = 0;

        for(int i = k ; i <= arr.size(); i++){
            if (currSum/k >= threshold){
                res++;
            }
            if (i == arr.size()){
                break;
            }
            currSum -= arr[l];
            l++;

            currSum += arr[i];
        }
        return res;
    }
};