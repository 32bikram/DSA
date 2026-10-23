class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int k = 0; bool flag = false;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]!=i){
                if(!flag){
                    k = nums[i]; 
                    flag = true;
                }
                else k = k & nums[i];
            }
        }
        return k;
    }
};
