class Solution {
public:
    bool isNStraightHand(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int val, count, temp_k;

        for(int i  = 0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        sort(nums.begin(), nums.end());

        for(int i=0; i<nums.size(); i++){
            val = nums[i];
            if(mp.find(val)==mp.end()) continue; //already consumed values
            count = mp[val];
            mp.erase(val);
            val++;
            int temp_k = k-1; //because for already 1 we are finding the rest so for k =4 we are finding the rest 3
            while(temp_k--){
                if(mp.find(val)!=mp.end()){
                    if(mp[val]>=count) mp[val]-=count;
                    else return false;

                    if(mp[val]==0) mp.erase(val);
                }
                else return false;
                val++;
            }
        }
        return true;
    }
};
