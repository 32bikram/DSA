class Solution {
public:
    int minSwaps(vector<int>& nums) {
        vector<int> nums2 = nums;
        int t = 0, temp = 0;
        for(int i = 0; i<nums2.size(); i++){
            t = nums2[i];
            temp = 0;
            while(t>0){
                temp += t %10;
                t /= 10;
            }
            nums2[i] = temp;
        }

        vector<pair<int,int>> sorted_nums;
        for(int i = 0; i<nums2.size(); i++){
            sorted_nums.push_back({nums2[i],nums[i]}); //sum, actual number
        }
        sort(sorted_nums.begin(), sorted_nums.end()); // sort based on sum

        unordered_map<int,vector<int>> mp; //actual number, [unordered pos, correct pos]
        for(int i = 0; i<nums.size(); i++){ //inserting current position
            mp[nums[i]].push_back(i);
        }
        for(int i = 0; i<sorted_nums.size(); i++){ //inserting correct position
            mp[sorted_nums[i].second].push_back(i);
        }
        int key, swap_count = 0, to_be_swapped_with; vector<int> value;
        for(auto it = mp.begin(); it != mp.end(); it++){
            key = it->first, value = it->second;
            if(value[0]!=value[1]){
                swap_count++;
                to_be_swapped_with = nums[value[1]];
                mp[to_be_swapped_with][0] = value[0];
                swap(nums[value[0]], nums[value[1]]);
            }
        }
        return swap_count;
    }
};
