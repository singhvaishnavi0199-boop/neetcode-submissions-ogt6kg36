class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int minBoats = 0;
        sort(people.begin(), people.end());
        int l = 0;
        int r = people.size()-1;

        while(l<r){
            if (people[l]+ people[r] > limit){
                minBoats++;
                r--;
            }else{
                minBoats++;
                l++;
                r--;
            }
        }
        if (l==r){
            minBoats++;
        }

        return minBoats;
    }
};