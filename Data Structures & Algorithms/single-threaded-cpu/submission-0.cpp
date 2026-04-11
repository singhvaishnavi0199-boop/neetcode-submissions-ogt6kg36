#include <array>
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<int> result;
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> pending;
        priority_queue<pair<int,int>, vector<pair<int,int>> , greater<>> available;

        for(int i= 0; i<tasks.size(); i++){
            // pending.push(array<int,3>{tasks[i][0], tasks[i][1], i});
            pending.push({tasks[i][0], tasks[i][1], i});
        }

        int time = 0;
        while(!pending.empty() || !available.empty()){
            while(!pending.empty() && time >= pending.top()[0]){
                auto [enqueue, process, index] = pending.top();
                pending.pop();
                available.push({process, index});
            }
            if (available.empty()){
                time = pending.top()[0];
                continue;
            }

            auto [process, index] = available.top();
            available.pop();
            time += process;
            result.push_back(index);
        }

        return result;
    }
};