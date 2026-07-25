class Solution {
public:
    int cost1, cost2;

    int dfs(int idx, vector<int> &dp, vector<int> &cost){
        if(idx>=cost.size()) return 0;
        if(dp[idx]!=-1) return dp[idx];

        cost1 = dfs(idx+1,dp,cost);
        if(idx+1<cost.size()) cost1 += cost[idx+1];
        cost2 = dfs(idx+2,dp,cost);
        if(idx+2<cost.size()) cost2 += cost[idx+2];
        
        dp[idx] = min(cost1,cost2);
        return min(cost1,cost2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(), -1);
        cost1 = dfs(0,dp,cost);
        if(0<cost.size()) cost1 += cost[0];
        cost2 = dfs(1,dp,cost);
        if(1<cost.size()) cost2 += cost[1];
        return min(cost1,cost2);
    }
};
