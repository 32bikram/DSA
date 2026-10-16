class Solution {
public:
    int minimumCost(vector<int>& cost) {
        if(cost.size()==1) return cost[0];
        sort(cost.begin(), cost.end(), greater<int>());
        int i = 0, ans = 0;
        while(i < cost.size()){
            if(i+1<cost.size()){
                ans += cost[i] + cost[i+1];
            }
            else ans += cost[i];
            i += 3;
        }
        return ans;
    }
};
