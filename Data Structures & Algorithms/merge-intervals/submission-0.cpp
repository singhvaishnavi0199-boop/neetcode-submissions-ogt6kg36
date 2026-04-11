class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        int n = intervals.size();
        // sort the intervals in ascending order by start value
        sort(intervals.begin(), intervals.end());

        // append 1st interval 
        result.push_back(intervals[0]);

        // iterate through the list,
        // if last appended interval overlaps with the current, update it's value
        for(int i = 1 ; i < n ; i++){
            vector<int>& newInterval = intervals[i];
            vector<int>& lastInterval = result.back();

            if (lastInterval[1] < newInterval[0]){
                result.push_back(newInterval);
            }else{
                lastInterval[0] = min(lastInterval[0], newInterval[0]);
                lastInterval[1] = max(lastInterval[1], newInterval[1]);
            }
        }

        return result;
    }
};
