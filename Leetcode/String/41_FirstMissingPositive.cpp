class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]<0) nums[i] = 0;
        }
        for(int i = 0; i<nums.size(); i++){
            if(abs(nums[i])-1>=nums.size() || nums[i]==0) continue;
            if(nums[abs(nums[i])-1]>0) nums[abs(nums[i])-1] *= -1;
            else if(nums[abs(nums[i])-1]==0) nums[abs(nums[i])-1] = -1*abs(nums[i]);
        }
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]>=0) return i+1;
        }
        return nums.size()+1;
    }
};
