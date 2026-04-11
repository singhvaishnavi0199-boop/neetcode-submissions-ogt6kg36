class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        //check if deadends has '0000'

        unordered_set<string> visit(deadends.begin(), deadends.end());
        if (visit.count("0000")){
            return -1;
        }
        // treat deadends as visited nodes , we don't want to visit them.

        // queue , push '0000' to it. // no of moves = 0;
        queue<pair<string,int>> q; //(lock, turn)
        q.push({"0000",0});
        visit.insert("0000");

        // while queue is not empty
        // pop the front
        // for each char : increament 1 and decrement 1 
        // if target reached , return moves +1;
        // if in visited , do nothing
        // else push in the queue.
        // increment moves by 1

        while(!q.empty()){
           string lock = q.front().first;
           int turn = q.front().second;
           q.pop();

           if(lock==target){
            return turn;
           }

           vector<string> nextLocks;
           nextLocks = children(lock);

           for (int i =0; i< nextLocks.size(); i++){
            if (!visit.count(nextLocks[i])){
                visit.insert(nextLocks[i]);
                q.push({nextLocks[i], turn+1});
            }
           }
        }


        // if queue becomes empty, then return -1
        return -1;
    }


private:
    vector<string> children (string lock){
        vector<string> result;
        for (int i=0;i<4;i++){
            string increment = lock;
            increment[i] = (lock[i] - '0' + 1) % 10 + '0';
            result.push_back(increment);

            string decrement = lock;
            decrement[i] = (lock[i] - '0' - 1 + 10) % 10 + '0';
            result.push_back(decrement);
        }
        return result;
    }
};