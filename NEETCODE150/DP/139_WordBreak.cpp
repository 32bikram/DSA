class Solution {
public:
    int dfs(unordered_set<string> &st, vector<int> &dp, string &s, int idx){
        if(idx>=s.size() || dp[idx]==1) return 1;
        if(dp[idx]==-1) return -1;
        string t = "";
        for(int i = idx; i<s.size(); i++){
            t += s[i];
            if(st.contains(t)){
                dp[idx] = dfs(st, dp, s, i+1);
                if(dp[idx]==1) return 1; //true hole sathe sathe return korai dichi but false
                //hole korachi na karon ami dekhte chai if samne kono solution paoa jay ki na
                //ultimately jodi paoa na jay then -1 e thaike jabe r change korte lagbe na
            }
        }
        return -1;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        vector<int> dp(s.size(), 0);
        for(string s : wordDict){
                st.insert(s);
        }
        int ans = dfs(st, dp, s, 0);
        if(ans==1) return true;
        return false;
    }
};
