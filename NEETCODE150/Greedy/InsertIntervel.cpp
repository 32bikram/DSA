class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int new_left = newInterval[0], new_right = newInterval[1];
        vector<vector<int>> ans;
        while(i<intervals.size() && intervals[i][1]<new_left){ //no overlap
            ans.push_back(intervals[i]);
            i++;
        }
        while(i<intervals.size() && intervals[i][0]<=new_right){ //overlap starts till overlap persists
            new_left = min(new_left, intervals[i][0]);
            new_right = max(new_right, intervals[i][1]);
        }
        ans.push_back({new_left,new_right});
        while(i<intervals.size()){
            ans.push_back(intervals[i]);
        }
        return ans;
    }
};
