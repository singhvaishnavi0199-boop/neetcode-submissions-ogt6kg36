class TimeMap {
private :
    unordered_map<string, vector<pair <int,string>>> mp;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        string result = "";
        if (!mp.count(key)){
            return result;
        }
        auto values = mp[key];
        int l = 0;
        int r = values.size()-1;

        while(l<= r){
            int m = l + (r-l)/2;
            if (values[m].first  == timestamp){
                return values[m].second;
            }else if (values[m].first < timestamp){
                result = values[m].second;
                l = m+1;
            }else{
                r = m-1;
            }
        }
        return result;
    }
};
