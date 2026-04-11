class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        // sort the meetings in ascending start time order
        sort(meetings.begin(), meetings.end());
        // array of size n to maintain meeting count
        vector<int> count (n,0);
        // (end, room no) - min heap
        priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>> inUse;
        // min heap to get smallest no of free room
        priority_queue<int, vector<int> , greater<int>> freeRoom;
        for(int i=0 ; i<n ; i++){
            freeRoom.push(i);
        }

        for(int i = 0; i<meetings.size() ; i++){
            int start = meetings[i][0];
            int end = meetings[i][1];

            // first check if the any room is getting emptied 
            // before checking total no of free rooms

            while(!inUse.empty() && inUse.top().first <= start){
                int room = inUse.top().second;
                inUse.pop();
                freeRoom.push(room);
            }

            //now if no room is free

            if(freeRoom.empty()){
                int room = inUse.top().second;
                int time = inUse.top().first;
                inUse.pop();
                end = time + (end-start);
                freeRoom.push(room);
            }

            // now rooms will be free
            int room = freeRoom.top();
            freeRoom.pop();
            inUse.push({end,room});
            count[room]++;
           
        }

        int maxMeetingRoom = 0;
        int meetingCounts = 0;
        for(int i=0 ; i<n ; i++){
            if (count[i] > meetingCounts){
                maxMeetingRoom = i;
                meetingCounts = count[i];
            }
        }

        return maxMeetingRoom;
    }
};