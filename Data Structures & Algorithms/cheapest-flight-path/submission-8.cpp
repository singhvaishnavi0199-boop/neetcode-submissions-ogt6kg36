class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // build an adj list
        unordered_map<int , vector<pair<int,int>>> adj;
        for( auto &flight : flights){
            int source = flight[0];
            int dest = flight[1];
            int price = flight[2];
            if (adj.count(source)== 0){
                adj[source] = {};
            }
            if (adj.count(dest)== 0){
                adj[dest] = {};
            }
            adj[source].push_back({dest, price});
        }

        // min priority queue - price, node, count
        priority_queue< pair<int, pair<int,int>> , vector<pair<int, pair<int,int>>> , greater<>> minHeap;

        // visited array - INT_MAX : cost to reach any node at the start
        vector<int> visited (n , INT_MAX);

        // push (0, src , -1)
        minHeap.push({0, {src, -1}});



        // pop 
        // check if count >= k : continue
        // visited[src] = min (curr, top)

        // push neighbours 

        while(!minHeap.empty()){
            auto node = minHeap.top();
            int price = node.first;
            int currNode = node.second.first;
            int stop = node.second.second;
            cout<< price <<" "<< currNode <<" "<< stop <<endl;
            minHeap.pop();

            // if (visited[currNode] < price){
            //     continue;
            // }

            visited[currNode] = min(price, visited[currNode]);

            if (stop >= k){
                continue;
            }

            for( auto &neigh : adj[currNode]){
                int nextNode = neigh.first;
                int amount = neigh.second + price;
                if (visited[nextNode] > amount){
                    minHeap.push({amount, {nextNode, stop+1}});
                    cout<<"pushed ";
                    cout<< amount <<" "<< nextNode <<" "<< stop+1 <<endl;
                }
            }
        }

        if (visited[dst] == INT_MAX){
            return -1;
        }
        return visited[dst];

        // if visited[dest] = INT_MAX , return -1 else visited[dest]
    }
};
