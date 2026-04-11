class Solution {
public:
    string foreignDictionary(vector<string>& words) {

        //initializing adj list and indegree for all characters
        unordered_map<char, vector<char>> adj;
        unordered_map<char,int> indegree;
        for(const auto& word:words){
            for(const auto& character: word){
                adj[character];
                indegree[character]= 0;
            }
        }

        //adj list for characters
        for(int i=0 ; i<words.size()-1; i++){
            string word1 = words[i];
            string word2 = words[i+1];
            if(word2.size()<word1.size() && word2 == word1.substr(0,word2.size())){
                return "";
            }
            for(int j =0 ;j<min(word1.size() , word2.size()); j++){
                if (word1[j] != word2[j]){
                    adj[word1[j]].push_back(word2[j]);
                    break;
                }
            }
        }

        //calculating indegree of all characters
        for(auto& [elem, neighbours] : adj){
            for(auto& neigh: neighbours){
                indegree[neigh]++;
            }
        }

        //topo sort - kahn's algo
        queue<char> q;
        for(auto& [c, deg] : indegree){
            if(deg==0){
                q.push(c);
            }
        }

        //intialize result;
        string result = "";

        while(!q.empty()){
            char elem = q.front();
            q.pop();
            result.push_back(elem);

            for (int i=0; i< adj[elem].size(); i++){
                indegree[adj[elem][i]]--;
                if(indegree[adj[elem][i]]== 0){
                    q.push(adj[elem][i]);
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
