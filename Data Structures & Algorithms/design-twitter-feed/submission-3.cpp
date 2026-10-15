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
            return get<2>(a) < get<2>(b);
        };

        priority_queue
        <
            tuple<int,int,int,int>, // { userId , index, count, tweetId }
            vector<tuple<int,int,int,int>>,
            decltype(cmp)
        > pq;

        for (int followeeId: followMap[userId]) {
            if (!tweetMap[followeeId].empty())
                pq.push({
                    followeeId, 
                    tweetMap[followeeId].size()-1, 
                    tweetMap[followeeId].back().first,
                    tweetMap[followeeId].back().second
                });
        }

        if (!tweetMap[userId].empty()) {
            pq.push({
                userId, 
                tweetMap[userId].size()-1, 
                tweetMap[userId].back().first,
                tweetMap[userId].back().second
            });
        }

        vector<int> res;

        for (int i=0; i<10 && !pq.empty(); i++) {
            auto& top = pq.top();
            res.push_back(get<3>(top));

            if (get<1>(top) > 0) {
                pq.push({
                    get<0>(top), 
                    get<1>(top)-1, 
                    tweetMap[get<0>(top)][get<1>(top)-1].first,
                    tweetMap[get<0>(top)][get<1>(top)-1].second
                });
            }

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
