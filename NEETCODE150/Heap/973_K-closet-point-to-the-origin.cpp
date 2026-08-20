class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,vector<int>>> pq;
        double cur_max, pq_max;
        for(vector<int> point : points){
            cur_max = sqrt((point[0]*point[0])+(point[1]*point[1]));
            if(!pq.empty()) pq_max = pq.top().first;
            if(pq.size()<k || pq_max>cur_max){
                pq.push({cur_max,point});
                while(pq.size()>k) pq.pop();
            }
        }
        vector<vector<int>> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
