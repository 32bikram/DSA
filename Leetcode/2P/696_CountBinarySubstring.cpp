class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int> vec;
        int prev = s[0], c = 1;
        for(int i = 1; i<s.size(); i++){
            if(s[i]!=prev){
                vec.push_back(c);
                prev = s[i];
                c=1;
            }
            else c++;
        }
        vec.push_back(c);
        int ans = 0;
        for(int i = 1; i<vec.size(); i++){
            ans += min(vec[i-1],vec[i]);
        }
        return ans;
    }
};
