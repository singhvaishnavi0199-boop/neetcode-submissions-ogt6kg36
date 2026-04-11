class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int r = nums1.size()-1;
        int l = m-1;
        while(l>=0){
            nums1[r] = nums1[l];
            r--;
            l--;
        }
        while(r>=0){
            nums1[r] = 0;
            r--;
        }

        int p1 = n;
        int p2 = 0;
        int i = 0;

        while (p1 < nums1.size() && p2 < n){
            if (nums1[p1] <= nums2[p2]){
                nums1[i]= nums1[p1];
                p1++;
            }else{
                nums1[i] = nums2[p2];
                p2++;
            }
            i++;
        }

        if (p1 == nums1.size()){
            while (i < nums1.size()){
                nums1[i] = nums2[p2];
                i++;
                p2++;
            }
        }

    }
};