class Twitter {
public:
    unordered_map<int,priority_queue<pair<int,int>>> pq; //user, time, pid
    vector <pair<int, pair<int,int>>> pq_copy; //user, time, pid
    unordered_map<int, unordered_set<int>> relation; //user, people he follows
    int my_time;

    Twitter() {
        my_time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        my_time++;
        if(relation.find(userId)==relation.end()){
            relation[userId] = {userId};
        }
        pq[userId].push({my_time, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        if(relation.find(userId)==relation.end()){
            relation[userId] = {userId};
        }
        vector<int> posts; //ans
        priority_queue<tuple<int,int,int>> cached_posts; //user,time,postid
        for(int a : relation[userId]){ //itr through all followed usr
            if(pq.find(a)!=pq.end()){ //checking if that folowed has post
                cached_posts.push({pq[a].top().first, pq[a].top().second, a}); //taking a post from all followed //time,pid,user
                pq_copy.push_back({a, pq[a].top()}); //keeping that post aside to restore //usr,time,pid
                pq[a].pop();
            }
        }
        while(posts.size()!= 10){
            if(cached_posts.empty()) break;
            auto t = cached_posts.top(); //earliest post among all followed
            cached_posts.pop();
            posts.push_back(get<1>(t)); 
            int prev_usr = get<2>(t); //whose followed post was taken
            if(!pq[prev_usr].empty()){
                cached_posts.push({pq[prev_usr].top().first, pq[prev_usr].top().second,prev_usr}); //time,pid,usr
                pq_copy.push_back({prev_usr, pq[prev_usr].top()}); //usr,time,pid
                pq[prev_usr].pop();
            }
        }
        for(auto a : pq_copy){
            pq[a.first].push(a.second);
        }
        pq_copy.clear();
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
