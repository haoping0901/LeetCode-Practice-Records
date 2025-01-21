// Record the following information for each user:
    // Following status (whether following or not -> set)
    // Posts (post ID + posting time required for fetching new posts 
    //        -> 2D vector)
// The above information corresponds to each user, meaning there is a mapping 
// -> map<...>
// To improve search efficiency -> use a hash map (unordered_map)

// Fetching new posts -> Get the latest ten posts from the users currently 
//                       being followed -> use a priority_queue

class Twitter {
    unordered_map<int, vector<vector<int>>> tweets_;
    unordered_map<int, set<int>> follow_;
    int count_;
public:
    Twitter() {
        count_ = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets_[userId].push_back({count_++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ret;
        auto tweets_cmp = [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        };
        priority_queue<vector<int>, 
                       vector<vector<int>>, 
                       decltype(tweets_cmp)> min_heap(tweets_cmp);

        follow_[userId].insert(userId);
        for (const int& followee_id: follow_[userId]) {
            if (tweets_.find(followee_id) != tweets_.end()) {
                const vector<vector<int>>& tweets = tweets_[followee_id];
                int idx = tweets.size() - 1;
                min_heap.push({tweets[idx][0], tweets[idx][1], followee_id, 
                               idx});
            }
        }

        while (!min_heap.empty() && ret.size() < 10) {
            auto cur_tweet = min_heap.top();
            min_heap.pop();
            ret.push_back(cur_tweet[1]);

            int idx = cur_tweet[3];
            if (idx > 0) {
                auto tweet = tweets_[cur_tweet[2]][idx-1];
                min_heap.push({tweet[0], tweet[1], cur_tweet[2], idx-1});
            }
        }

        return ret;
    }
    
    void follow(int followerId, int followeeId) {
        follow_[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follow_[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */