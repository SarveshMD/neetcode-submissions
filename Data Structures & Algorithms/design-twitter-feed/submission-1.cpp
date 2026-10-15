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
        auto cmp = [](const auto& a, const auto& b) {
            return a.first < b.first;
        };

        priority_queue
        <
            pair<int,int>,
            vector<pair<int,int>>,
            decltype(cmp)
        > pq;

        for (int followeeId: followMap[userId]) {
            for (auto& tweet: tweetMap[followeeId]) {
                pq.push(tweet);
            }
        }

        for (auto& tweet: tweetMap[userId]) {
            pq.push(tweet);
        }

        vector<int> res;
     
        for (int i=0; i<10 && !pq.empty(); i++) {
            res.push_back(pq.top().second);
            pq.pop();
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
