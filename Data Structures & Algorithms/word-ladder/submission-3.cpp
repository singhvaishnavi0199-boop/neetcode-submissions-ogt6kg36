class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if((beginWord == endWord) || find(wordList.begin(), wordList.end() , endWord) == wordList.end()){
            return 0;
        }

        int result =0;
        wordList.push_back(beginWord);

        unordered_map<string, vector<string>> patternMap;
        for(int i=0;i<wordList.size(); i++){
            string word = wordList[i];
            for(int j=0; j<word.size(); j++){
                string patternWord =  word.substr(0,j) + "*" + word.substr(j+1);
                patternMap[patternWord].push_back(word);
            }
        }

        unordered_set<string> visited;
        queue<string> q;
        q.push(beginWord);
        visited.insert(beginWord);

        while(!q.empty()){
            result++;
            int qsize = q.size();
            for(int k =0; k<qsize; k++){
                string word = q.front();
                q.pop();

                if(word == endWord){
                    return result;
                }

                for(int i =0 ; i<word.size(); i++){
                    string patternWord =  word.substr(0,i) + "*" + word.substr(i+1);
                    for(int j=0; j<patternMap[patternWord].size(); j++){
                        if (visited.find(patternMap[patternWord][j]) == visited.end()){
                            q.push(patternMap[patternWord][j]);
                            visited.insert(patternMap[patternWord][j]);
                        }
                    }
                }
            }
        }

        return 0;
    }
};
