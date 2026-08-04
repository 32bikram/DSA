class Solution {
public:
    int fun(vector<int> &dp, vector<int> &nums){
        int l = 0, r=0;
        int ans = INT_MIN;
        int temp = 1;
        while(l<nums.size()){
            if(nums[l]>0){
                temp *= nums[l];
                ans = max(ans, temp);
            }
            else if(nums[l]==0){
                ans = max(ans , 0);
                temp = 1;
            }
            else{
                if(temp<0){
                    temp *= nums[l];
                    ans = max(ans, temp);
                }
                else{
                    if(dp[l]!=-1){
                        temp *= nums[l];
                        ans = max(ans, temp);
                    }
                    else{
                        int k = dp[r];
                        if(k!=-1 && dp[k]!=-1){
                            l = k;
                            r = k;
                            temp = nums[l];
                        }
                        else{
                            r = l+1;
                            temp = 1;
                        }
                    }
                }
            }
            l++;
        }
        return ans;
    }

    int maxProduct(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        vector<int> dp(nums.size(), -1);
        int neg_idx = -1;
        for(int i = nums.size()-1; i>=0; i--){
            dp[i] = neg_idx;
            if(nums[i]<0) neg_idx = i;
            else if(nums[i]==0) neg_idx = -1;
        }
        return fun(dp, nums);
    }
};
