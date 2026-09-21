class Solution {
public:
    int jump(vector<int>& nums) {
        int cur_max = 0, future_max = 0, jump = 0;
        for(int i = 0; i<nums.size(); i++){
            future_max = max(future_max, nums[i]+i);
            if(i==cur_max){
                cur_max = future_max;
                if(i!=nums.size()-1) jump++;
            }
        }
        return jump;
    }
};
