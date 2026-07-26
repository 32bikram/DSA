class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN;
        int nege = INT_MIN;
        int sum = 0;
        int r = 0;
        while(r<nums.size()){
            int temp = sum;
            temp += nums[r];
            if(nums[r]<0) nege = max(nege, nums[r]);
          
            if(temp<0){
                sum = 0;
                r++;
                continue;
            }
          
            sum = temp;
            ans = max(sum, ans);
            r++;
        }
        return max(ans,nege);
    }
};

https://youtu.be/HHS_Myn-Y1Y?si=zy97z_9LwQV2ZGsQ
