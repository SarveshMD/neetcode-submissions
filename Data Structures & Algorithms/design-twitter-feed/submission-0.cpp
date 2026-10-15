class Twitter {
public:
    unordered_map<int, unordered_set<int>> followMap; // {userId, {followee list}}
    unordered_map<int, vector<pair<int, int>>> tweetMap; // {userId, {(count, tweetId)...}}
    int curr_count = 0;

    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        this->tweetMap[userId].push_back({this->curr_count, tweetId});
        this->curr_count++;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<pair<int,int>> posts;
        for (int followeeId: followMap[userId]) {
            posts.insert(posts.end(), tweetMap[followeeId].begin(), tweetMap[followeeId].end());
        }

        posts.insert(posts.end(), tweetMap[userId].begin(), tweetMap[userId].end());

        sort(posts.begin(), posts.end(), [](auto& a, auto& b) {
            return a.first > b.first;
        });

        vector<int> res;
        for (int i=0; i<10 && i < posts.size(); i++) {
            res.push_back(posts[i].second);
        }
        return res;

    }
    
    void follow(int followerId, int followeeId) {
        this->followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        this->followMap[followerId].erase(followeeId);
    }
};
