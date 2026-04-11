class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> incoming (n+1,0);
        vector<int> outgoing (n+1,0);

        for (int i=0;i<trust.size(); i++){
            incoming[trust[i][1]]++;
            outgoing[trust[i][0]]++;
        }

        for (int i=1;i<n+1;i++){
            if (incoming[i]== n-1 && outgoing[i]==0){
                return i;
            }
        }
        return -1;
    }
};