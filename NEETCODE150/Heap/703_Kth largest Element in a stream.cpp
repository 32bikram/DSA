class KthLargest {
public:
    vector<int> nums1;
    int k1;
    KthLargest(int k, vector<int>& nums) {
        nums1 = nums;
        k1 = k;
        make_heap(nums1.begin(), nums1.end(), greater<int>());
        while(nums1.size()>k1){
            pop_heap(nums1.begin(), nums1.end(), greater<int>());
            nums1.pop_back();
        } 
    }
    int add(int val) {
        nums1.push_back(val);
        push_heap(nums1.begin(),nums1.end(), greater<int>());
        while(nums1.size()>k1){
            pop_heap(nums1.begin(), nums1.end(), greater<int>());
            nums1.pop_back();
        } 
        return nums1[0];
    }
};
