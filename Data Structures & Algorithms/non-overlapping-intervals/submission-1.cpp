class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ans  = 0;
        sort(intervals.begin(), intervals.end());
        int i = 0;
        int n = intervals.size();
        // int s1 = intervals[0][0];
        int e1 = intervals[0][1];

        for(int i =1 ; i<n ; i++){
            int s2 = intervals[i][0];
            int e2 = intervals[i][1];

            if(e1<=s2){
                // s1 = s2;
                e1 = e2;
            }else{
                ans++;
                e1 = min (e1, e2);
            }
        }

        return ans;
    }
};
