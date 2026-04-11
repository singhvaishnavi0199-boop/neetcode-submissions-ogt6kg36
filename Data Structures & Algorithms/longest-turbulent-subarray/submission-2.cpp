class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int maxSize = 1;
        int currSize = 1;
        int n = arr.size();
        int prevComp = 0;
        int currComp = 0;

        for(int i= 1; i<n ; i++){
            if (arr[i-1] < arr[i]){
                currComp = -1;
            }else if (arr[i-1] > arr[i]){
                currComp = 1;
            }else{
                currComp = 0;
            }

            if (currComp == 0){
                currSize = 1;
            }
            else if (currComp != prevComp){
                currSize++;
            }else{
                currSize = 2;
            }

            maxSize = max (currSize, maxSize);
            prevComp = currComp;
        }

        return maxSize;
    }
};