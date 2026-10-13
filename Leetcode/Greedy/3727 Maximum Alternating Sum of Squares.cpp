class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]<0) nums[i]=(-1)*nums[i];
        }
        long long ans = 0; int i = 0, j = 0, n = nums.size();
        sort(nums.begin(), nums.end());
        while(i<n/2){
            j = n-(i+1);
            ans += nums[j] * nums[j];
            ans -= nums[i] * nums[i];
            i++;
        }
        if(n%2!=0){
            ans += nums[(n/2)] * nums[(n/2)];
        }
        return ans;
    }
};
