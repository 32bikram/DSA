class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> mp;
        unordered_set<char> st;
        for(char c : s){
            mp[c]++;
        }

        vector<int> ans;
        int temp = 0;
        for(int i = 0; i<s.size(); i++){
            if(mp[s[i]]==1 && st.empty()){
                ans.push_back(1);
                mp[s[i]]--;
            }
            else{
                temp++;
                mp[s[i]]--;
                if(mp[s[i]]==0) st.erase(s[i]);
                else st.insert(s[i]);
                if(mp[s[i]]==0 && st.empty()){
                    ans.push_back(temp);
                    temp = 0;
                }
            }
        }
        return ans;
    }
};
