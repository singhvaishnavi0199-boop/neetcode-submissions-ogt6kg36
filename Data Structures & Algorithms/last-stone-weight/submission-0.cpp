class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue <int> pq;
        for (int i=0;i<stones.size();i++){
            pq.push(stones[i]);
        }

        while(pq.size()>1){
            int ele1 = pq.top();
            pq.pop();
            int ele2 = pq.top();
            pq.pop();
            if (ele1==ele2){
                continue;
            }else{
                pq.push(abs(ele1-ele2));
            }
        }

        if (pq.empty()){
            return 0;
        }else{
            return pq.top();
        }
    }
};
