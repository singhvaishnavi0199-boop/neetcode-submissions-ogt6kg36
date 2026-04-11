class Twitter {
public:

    int counter;
    unordered_map<int, unordered_set<int>> followerMap;
    unordered_map<int, vector<pair<int,int>>> tweetMap;

    Twitter() {
        counter = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back({counter++, tweetId});
        // if(tweetMap[userId].size()>10){
        //     tweetMap[userId].erase(tweetMap[userId].begin());
        // }
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> result;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> newsFeed;
        for(int i=0; i<tweetMap[userId].size(); i++){
            newsFeed.push(tweetMap[userId][i]);
            if (newsFeed.size()>10){
                newsFeed.pop();
            }
        }


        for (int followee : followerMap[userId]) {
            for (auto &tweet : tweetMap[followee]) {
                newsFeed.push(tweet);
                if (newsFeed.size() > 10) {
                    newsFeed.pop();
                }
            }
        }


        while(!newsFeed.empty()){
            result.push_back(newsFeed.top().second);
            newsFeed.pop();
        }
        reverse(result.begin(), result.end());
        return result;

    }
    
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId){
            followerMap[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        if (followerMap[followerId].count(followeeId)){
            followerMap[followerId].erase(followeeId);
        }
    }
};
