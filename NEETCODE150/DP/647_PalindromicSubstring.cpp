
class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0;
        int l = 0, r = 0; 

        for(int i = 0; i<s.size(); i++){

            l = i-1, r = i+1;
            while(r<s.size() && l>=0){
                if(s[l]==s[r]){
                    ans++;
                    l--; r++;
                }
                else break;
            }

            l = i-1, r = i;
            while(r<s.size() && l>=0){
                if(s[l]==s[r]){
                    ans++;
                    l--; r++;
                }
                else break;
            }
        }
        ans += s.size(); //single chars
        return ans;
    }
};
