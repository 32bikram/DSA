class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st;
        int maxm = INT_MIN;
        for(int i : nums){
            st.insert(i);
            if(i%k==0) maxm = max(maxm, i);
        }
        int t = 1;
        while(t*k<=maxm){
            if(!st.contains(t*k)) return t*k;
            t++;
        }
        return t*k;
    }
};
