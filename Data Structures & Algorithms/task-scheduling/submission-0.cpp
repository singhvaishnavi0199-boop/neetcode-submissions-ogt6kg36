class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int time = 0;
        vector<int> freq(26,0);
        for(int i = 0; i< tasks.size(); i++){
            freq[tasks[i] - 'A']++;
        }

        priority_queue<int> maxHeap;
        for(int i=0; i<26; i++){
            if (freq[i] > 0){
                maxHeap.push(freq[i]);
            }
        }

        queue<pair<int,int>> q; // remaining_cnt, next_time_available

        while(!maxHeap.empty() || !q.empty()){
            time++;

            if (!maxHeap.empty()){
                int curr = maxHeap.top();
                maxHeap.pop();
                if (curr-1 > 0){
                    q.push({curr-1, time+n});
                }
            }

            if (!q.empty() && q.front().second == time){
                auto available = q.front();
                q.pop();
                maxHeap.push(available.first);
            }
        }

        return time;
    }
};
