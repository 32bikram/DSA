class Solution {
public:

    int back(string &s, int idx, vector<int> &dp){
        if(idx >= s.size()) return 1;
        if(s[idx]=='0') return 0;
        if(dp[idx]!=-1) return dp[idx]; 
        int ans = 0;

        if(idx+1<s.size() && s[idx+1]=='0'){
            if((s[idx]-'0')*10 + s[idx+1]-'0' <=26){
                ans += back(s, idx+2, dp);
            }
            else return 0;
        }
        else{
            if(idx+1<s.size() && (s[idx]-'0')*10 + s[idx+1]-'0' <=26 ){
                ans += back(s, idx+2, dp);
            }
            ans += back(s, idx+1, dp);
        }
        dp[idx] = ans;
        return ans;
    } 
    int numDecodings(string s) {
        vector<int> dp(s.size(), -1);
        if(s[0]=='0') return 0;
        return back(s, 0, dp);
    }
};
