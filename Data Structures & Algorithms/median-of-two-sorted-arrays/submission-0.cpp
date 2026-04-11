class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> A = nums1;
        vector<int> B = nums2;
        int total = A.size() + B.size();
        int half = total / 2;

        if (A.size() > B.size()){ 
            swap(A,B);
        }
        // A is the smaller size array

        int l = 0;
        // int r = A.size()-1;
        int r = A.size(); // looking for equal partition and not indices.

        while(l<=r){
            // int i = l + (r-l)/2;
            // cout<<i<<endl;
            // int j = half - i - 2;
            // cout<<j<<endl;
            // // looking for equal partition and not indices.

            int i = (l+r) /2;
            int j = half - i;

            // int Aleft = i >= 0 ? A[i] : INT_MIN;
            // int ARight = i < A.size()-1 ? A[i+1] : INT_MAX;
            // int Bleft = j >= 0 ? B[j] : INT_MIN;
            // int BRight = j < B.size()-1 ? B[j+1] :INT_MAX;
            int Aleft = i > 0 ? A[i-1] :INT_MIN;
            int ARight = i < A.size() ? A[i] : INT_MAX;
            int Bleft = j > 0 ? B[j-1] : INT_MIN;
            int BRight = j < B.size() ? B[j] :INT_MAX;

            if(max(Aleft, Bleft) > min(ARight, BRight)){
                cout<<"yes"<<endl;
                if (Aleft < BRight){
                    l = i+1;
                }else{
                    r = i-1;
                }
            }else{
                if (total%2 == 0){
                    cout<<"here"<<endl;
                    cout<<Aleft<<" "<<Bleft<<" "<<ARight <<" "<<BRight <<endl;
                    return (max(Aleft, Bleft) + min(ARight, BRight))/2.0;
                }else{
                    cout<<"here2"<<endl;
                    return min(ARight, BRight);
                }
            }
        }
        return -1;
    }
};
