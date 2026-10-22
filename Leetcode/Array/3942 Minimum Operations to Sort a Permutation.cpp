class Solution {
public:
    int minOperations(vector<int>& nums) {
        // based on previous day problem array must be already sort in asc or desc order just need rotation.

        // first check if it sorted rotated arr
        int count = 0, n = nums.size();
        bool asc = false, desc = false;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] > nums[i]) count++;
        }
        if(nums[n-1] > nums[0]) count++;
        if(count <= 1) asc = true;
        else{ //not sorted ascending, check if descending
            count = 0;
            for (int i = 0; i < nums.size()-1; i++) {
                if (nums[i + 1] > nums[i]) count++;
            }
            if(nums[n-1] < nums[0]) count++;
            if(count>1) return -1;
            else desc = true;
        }
        int z_idx = 0, ans = INT_MAX;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]==0){
                z_idx = i;
                break;
            }
        }
        //take zero at first
        if(asc){
            ans = min(ans, z_idx); //just take zero to first idx
            ans = min(ans, (n-z_idx+1)+1); //zero in second half, so reverse take zero in first half then rotate
        }
        //take zero at last then reverse
        else if(desc){
            ans = min(ans, z_idx+2); //rotate to take 0 last, then reverse 10432
            ans = min(ans, (n-z_idx-1)+1); // zero in second half just take zero to last then reverse
        }
        if(ans!=INT_MAX) return ans;
        return -1;
    }
};
