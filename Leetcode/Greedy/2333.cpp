class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        vector<int> mp (1000011,0);
        int maxm = 0, k = k1+k2;;
        for(int i = 0; i<nums1.size(); i++){
            mp[abs(nums1[i]-nums2[i])]++;
            maxm = max(maxm, abs(nums1[i]-nums2[i]));
        }
        for(int i = maxm; i>=0; i--){
            if(k==0) break;
            if(mp[i]==0) continue;
            int removed = min(k, mp[i]);
            k -= removed; mp[i]-=removed;
            if(i-1>=0) mp[i-1] += removed;
        }
        long long ans = 0;
        for(long long i = 0; i<mp.size(); i++){
            ans += (i*i) * mp[i];
        }
        return ans;
    }
};
