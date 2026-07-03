class Solution {
public:
    vector<vector<string>> ans;
    vector<string> temp;

    bool palindrome(string s){
        int l = 0, r = s.size()-1;
        while(l<r){
            if(s[l]!=s[r]) return false;
            l++; r--;
        }
        return true;
    }
    
    void dfs(int idx, string s){
        if(idx == s.size()){
            ans.push_back(temp);
            return;
        }
        for(int j = idx; j<s.size(); j++){
            if(palindrome(s.substr(idx, j-idx+1))){
                temp.push_back(s.substr(idx, j-idx+1));
                dfs(j+1, s);
                temp.pop_back();
            }
        }
        return;
    }

    vector<vector<string>> partition(string s) {
        dfs(0, s);
        return ans;
    }
};

