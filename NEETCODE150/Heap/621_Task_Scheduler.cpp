class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<pair<int,char>> vec(26,{0,'A'});
        for(char task : tasks){
            vec[task-'A'].first += 1;
            vec[task-'A'].second = task;
        }
        priority_queue<pair<int,char>> pq;
        for(auto p : vec){
            if(p.first>0){
                pq.push(p);
            }
        }

        int ans = 0;
        int time = 1;
        queue<pair<int,pair<int,char>>> q;
        while(!pq.empty() || !q.empty()){
            if(!pq.empty()){
                auto p = pq.top();
                pq.pop();
                p.first-=1;
                if(p.first!=0) q.push({time+n+1,p}); // n sec wait and 1 for its own turn
            }
            time++;
            ans++;
            if(!q.empty() && q.front().first==time){
                    pq.push(q.front().second);
                    q.pop();
            }
        }
        return ans;
    }
};
