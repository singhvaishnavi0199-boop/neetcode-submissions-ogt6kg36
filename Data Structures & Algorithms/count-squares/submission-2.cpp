class CountSquares {
private:
    map<pair<int,int> , int> mp;
public:
    CountSquares() {
        mp.clear();
    }
    
    void add(vector<int> point) {
        mp[{point[0], point[1]}]++;
    }
    
    int count(vector<int> point) {
        int px = point[0];
        int py = point[1];
        int res = 0;

        for( auto &it : mp){
            int x = it.first.first;
            int y = it.first.second;

            // if (mp.count({px,y}) && mp.count({x,py})){ //checking rectangles
            //     res += (mp[{px,y}] * mp[{x,py}] * mp[{x,y}]);
            //     cout<<"res "<<res<<endl;
            // }

            if (abs(px-x) == abs(py-y) && px != x && py != y){
                res += (mp[{px,y}] * mp[{x,py}] * mp[{x,y}]);
            }
        }
        return res;
    }
};
