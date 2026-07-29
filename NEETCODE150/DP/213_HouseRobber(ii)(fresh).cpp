class Solution {
public:
    int dp(vector<int> &nums, int l, int r){
        vector<int> dp(nums.size());

        dp[l] = nums[l];
        dp[l+1] = max(nums[l], nums[l+1]);

        for(int i = l+2; i<r+1; i++){
            dp[i] = max(dp[i-2]+nums[i], dp[i-1]);
        }
        return dp[r];
    }

    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);
        
        int a = dp(nums, 0, nums.size()-2);
        int b = dp(nums, 1, nums.size()-1);
        return max(a,b);
    }
};
