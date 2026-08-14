class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        make_heap(nums.begin(),nums.end());
        int t = 0;
        while(!nums.empty()){
            t++;
            if(t==k) return nums.front();
            pop_heap(nums.begin(),nums.end());
            nums.pop_back();
        }
        return 0;
    }
};
