class Solution {
public:
    string reorganizeString(string s) {
        string res = "";
        unordered_map<char,int> freq;
        priority_queue <pair<int, char>> pq;

        //iterate over string and put char with freq into map
        for (char &c:s){
            freq[c]++;
        }

        // iterate over map, push freq-char into max heap
        for(auto &c:freq){
            pq.push({c.second,c.first});
        }

        pair<int,char> prev = {0,' '};
        while(!pq.empty() || prev.first>0){
            if (prev.first > 0 && pq.empty()) {
                return "";
            }
            char char_ = pq.top().second;
            int count = pq.top().first;
            pq.pop();
            res += char_;
            count--;

            if (prev.first>0){
                pq.push(prev);
            }
            prev = {count, char_};
        }
        return res;
    }
};