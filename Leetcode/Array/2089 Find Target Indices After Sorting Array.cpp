class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        //cal nums less than target
        //number of targets
        int count = 0, presence = 0;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]<target) count++;
            else if(nums[i]==target) presence++;
        }
        vector<int> ans;
        while(presence--){
            ans.push_back(count);
            count++;
        }
        return ans;
    }
};
