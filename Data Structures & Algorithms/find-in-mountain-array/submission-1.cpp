/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int getPeak (MountainArray &mountainArr){
       int l = 0;
       int length = mountainArr.length();
       int r = length-1;

       while(l<=r){
            int mid = l + (r-l)/2;
            if (mountainArr.get(mid-1) < mountainArr.get(mid) && mountainArr.get(mid) > mountainArr.get(mid+1)){
                cout<<"mid "<<mid<<endl;
                return mid;
            }else if (mountainArr.get(mid-1) < mountainArr.get(mid) && mountainArr.get(mid) < mountainArr.get(mid+1)){
                l = mid +1;
            }else{
                r = mid -1;
            }
       }
       cout<<"mid "<<"-1"<<endl;
       return -1;
    }

    int binarySearch(int l , int r , int target, bool asc ,MountainArray &mountainArr ){
        while(l<=r){
            int mid = l+(r-l)/2;
            cout<<"mid bs "<<mid<<endl;
            int val = mountainArr.get(mid);
            cout<<"val "<<val<<endl;
            if ( val == target){
                return mid;
            }
            if (asc == val < target){
                l = mid +1;
            }else{
                r = mid -1;
            }
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int length = mountainArr.length();
        int peak = getPeak(mountainArr);
        if (target == mountainArr.get(peak) ){
            return peak;
        }
        int res = binarySearch(0, peak, target, true, mountainArr );
        cout<<"res "<<res<<endl;
        if( res!= -1){
            return res;
        }else{
            return binarySearch(peak+1,length-1, target,false, mountainArr );
        }
    }
};