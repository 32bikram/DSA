class Solution {
public:
    int dp_fun(vector<int> &nums, int idx, vector<int> &dp){
        if(dp[idx]==1 || idx==nums.size()-1) return 1;
        else if(dp[idx]==0 || (nums[idx]==0&&idx!=nums.size()-1)) return 0;

        int maxjump_index = nums[idx]+idx; //till how many index we can go
        maxjump_index = min(maxjump_index, (int)nums.size()-1);
        int reachable = 0;
        for(int i = idx+1; i<=maxjump_index; i++){
            int a = dp_fun(nums, i, dp);
            dp[i] = a;
            if(a==1) reachable = 1;
        }
        return reachable;
    }
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(),-1); //0 = False, 1 = True for that index
        if(dp_fun(nums, 0, dp)==1) return true;
        return false;
    }
};
