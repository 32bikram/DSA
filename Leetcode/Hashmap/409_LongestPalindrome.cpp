class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;
        for(char c : s){
            mp[c]++;
        }
        int ans = 0;
        bool odd_flag = false;
        for(auto &p : mp){
            if(p.second%2==0) ans += p.second;
            else{
                ans += p.second-1;
                odd_flag = true; //one extra is there to be used as mid
                //like bcaaabc for a we add 2, but 1 more could be added a pivot
            }
        }
        if(odd_flag) ans += 1;
        return ans;
    }
};
