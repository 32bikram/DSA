class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        vector<int> vec(30,0); long mod = pow(10,9)+7;
        for(int i = 0; i<nums.size(); i++){
            int n = 0;
            while(n<30){
                vec[n] += (nums[i]>>n) & 1; //go from right most bit to left and also and with 1 to get only bit 1s 
                n++;
            }
        }
        long long ans = 0;
        while(k--){
            long long temp = 0;
            for(int i = 0; i<vec.size(); i++){
                temp += min(1,vec[i])* 1LL * pow(2,i);
                if(vec[i]>0) vec[i]--;
            }
            ans = (ans + 1LL * temp*temp) % mod;
        }
        return ans;
    }
};
