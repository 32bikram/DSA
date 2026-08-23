class Twitter {
public:
    priority_queue<pair<int, pair<int,int>>> pq;
    vector <pair<int, pair<int,int>>> pq_copy;
    unordered_map<int, unordered_set<int>> relation;
    int my_time;

    Twitter() {
        my_time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        my_time++;
        if(relation.find(userId)==relation.end()){
            relation[userId] = {userId};
        }
        pq.push({my_time, {tweetId, userId}});
    }
    
    vector<int> getNewsFeed(int userId) {
        if(relation.find(userId)==relation.end()){
            relation[userId] = {userId};
        }
        pair<int, pair<int,int>> temp;
        vector<int> posts;
        while(posts.size()!= 10){
            if(pq.empty()) break;
            temp = pq.top();
            pq.pop();
            pq_copy.push_back(temp);
            int poster_id = temp.second.second;
            if(relation[userId].contains(poster_id)){
                posts.push_back(temp.second.first);
            }
        }
        for(auto a : pq_copy){
            pq.push(a);
        }
        pq_copy = {};
        return posts;
    }
    
    void follow(int followerId, int followeeId) {
        if(relation.find(followerId)==relation.end()){
            relation[followerId] = {followerId};
        }
        if(relation.find(followeeId)==relation.end()){
            relation[followeeId] = {followeeId};
        }
        relation[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        relation[followerId].erase(followeeId);
    }
};
