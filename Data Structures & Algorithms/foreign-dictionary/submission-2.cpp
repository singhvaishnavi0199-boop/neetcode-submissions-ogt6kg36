class Solution {
public:
    string foreignDictionary(vector<string>& words) {

        string result = "";
        unordered_map<char,int> indegree;
        for(int i =0 ;i< words.size(); i++){
            for(int j = 0; j< words[i].size(); j++){
                indegree[words[i][j]] = 0;
            }
        }
        cout<<indegree.size()<<endl;
        
        // loop over 2 words
        // build adj list
        // do topo sorting
            // indegree
            // push 0 indegree to q
            // loop over all neighbours of front
            // indegree neigh -- , if = 0 , push to the queue
        unordered_map<char, vector<char>> adj;

        for(int i=0; i<words.size()-1; i++){
            string word1 = words[i];
            string word2 = words[i+1];
            int j = 0;
            while(j< word1.size() && j<word2.size() && word1[j]==word2[j]){
                j++;
            }
            if (j== word2.size() && j < word1.size()){
                return "";
            }
            if (j != word1.size()){
                adj[word1[j]].push_back(word2[j]);
                indegree[word2[j]]++;
            }
        }

        queue<char> q;
        for(auto c: indegree){
            char ele = c.first;
            int degree = c.second;
            if (degree == 0){
                q.push(ele);
            }
        }

        while(!q.empty()){
            int c = q.front();
            result += c;
            q.pop();

            for(auto neigh : adj[c]){
                indegree[neigh]--;
                if(indegree[neigh]==0){
                    q.push(neigh);
                }
            }
        }

        //detect cycle: some characters are not processed and hence the cycle
        if (result.size()<indegree.size()){
            return "";
        }

        return result;
    }
};
