class Solution {
public:
    int dp_fun(int idx, vector<int> &nums, vector<int> &dp){
        if(dp[idx]!=-1) return dp[idx];

        if(idx+2 >= nums.size()){ //last and second last index
            dp[idx] = nums[idx];
            return dp[idx];
        }
        int ans = 0;
        for(int i = idx+2; i<nums.size(); i++){
            ans = max(dp_fun(i, nums, dp), ans);
        }
        dp[idx] = ans+nums[idx];
        return dp[idx];
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        int ans = 0;
        if(nums.size()==1) return nums[0];
        dp_fun(0, nums, dp);
        dp_fun(1, nums, dp);
        return max(dp[0], dp[1]);
    }
};
