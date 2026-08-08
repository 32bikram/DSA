class Solution {
public:
    int dp_fun(vector<int>& dp, vector<int> &nums, int idx){
        if(dp[idx]!=-1) return dp[idx];
        int num = nums[idx];
        int count = 0;
        for(int i = idx+1; i<nums.size(); i++){
            int c = INT_MIN;
            if(nums[i]>num){
                c = dp_fun(dp, nums, i);
            }
            count = max(count, c);
        }
        dp[idx] = count+1;
        return count+1;
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        int ans = INT_MIN;
        for(int i = 0; i<nums.size(); i++){
            if(dp[i]!=-1) continue;
            int c = dp_fun(dp, nums, i);
            ans = max(c, ans);  
        }
        return ans;
    }
};
