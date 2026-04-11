class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>> maxHeap;
        if(a>0){
            maxHeap.push({a,'a'});
        }
        if(b>0){
            maxHeap.push({b,'b'});
        }
        if(c>0){
            maxHeap.push({c,'c'});
        }

        string ans = "";

        while(!maxHeap.empty()){
            // find the top pair
            // pop it
            // mark it as curr
            // if ans.size >= 2 , take last 2 elements, else take all the current elements
            // string substring = ans + curr elem
            // if substring == aaa, bbb, ccc
                // if maxheap is not empty 
                // take the nexttop elem and add it to the string
                // reduce the size
                // else
                // break
            // else
                // add the curr elem to the string
                // reduce the size
            // if size > 0 , push back the curr elem
            

            auto curr = maxHeap.top();
            maxHeap.pop();

            string sub = "";
            if (ans.size() >= 2){
                sub = ans.substr(ans.size()-2,2);
            }else{
                sub = ans;
            }
            sub += curr.second;

            if (sub == "aaa" || sub == "bbb" || sub == "ccc"){
                if (!maxHeap.empty()){
                    auto nextTop = maxHeap.top();
                    maxHeap.pop();
                    ans += nextTop.second;
                    nextTop.first--;
                    if(nextTop.first > 0){
                        maxHeap.push({nextTop.first, nextTop.second});
                    }
                }else{
                    break;
                }
            }else{
                ans += curr.second;
                curr.first--;
            }

            if(curr.first > 0){
                maxHeap.push({curr.first, curr.second});
            }
        }
        return ans;
    }
};