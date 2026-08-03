class Solution {
public:
    int dfs(vector<int> &coins, vector<int> &dp, int rem){
        if(dp[rem]!=-1) return dp[rem];
        if(rem == 0) return 0;
        int temp_rem = rem;
        int t = INT_MAX;
        // for(int i = coins.size()-1; i>=0; i--){
        for(int i = 0; i<coins.size(); i++){
            temp_rem = rem;
            temp_rem -= coins[i];
            if(temp_rem == 0){
                t = 0;
                break;
            }
            if(temp_rem>0){
                t = min(t, dfs(coins, dp, temp_rem));
            }
        }
        if(temp_rem==0 || t!=INT_MAX){
            dp[rem] = t+1;
            return t+1;
        }
        else{
            dp[rem] = INT_MAX;
            return INT_MAX;
        }

    }
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        // sort(coins.begin(), coins.end());
        vector<int> dp (amount+1, -1);
        int a = dfs(coins, dp, amount);
        if(a!=INT_MAX) return a;
        return -1;
    }
};
