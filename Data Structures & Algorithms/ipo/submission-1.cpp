class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int noOfProj = 0;
        // int maxProfit = 0;
        priority_queue<int> maxHeap;
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> minHeap;

        int n = profits.size();
        for(int i =0; i<n ;i++){
            minHeap.push({capital[i], profits[i]});
        }

        while(noOfProj < k){
            while(!minHeap.empty() && minHeap.top().first <= w){
                maxHeap.push(minHeap.top().second);
                minHeap.pop();
            }
            if (maxHeap.empty()) break;
            // maxProfit += maxHeap.top();
            w += maxHeap.top();
            maxHeap.pop();
            noOfProj++;
            
        }

        return w;
    }
};