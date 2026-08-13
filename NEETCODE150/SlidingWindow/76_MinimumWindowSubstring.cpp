class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> st;
        unordered_map<char, int> mp;
        int for_s[128] = {0};
        for(char c : t){
            for_t[c]++;
        }
        pair<int,int> p = {0,INT_MAX};
        int done = 0;
        int i = 0, j = 0;
        while(j<s.size()){
            if(st.find(s[j])!=st.end()){
                mp[s[j]]++;
                if(mp[s[j]]==st[s[j]]) done++;
            }
            while(done==st.size() && i<s.size()){
                while(!st.contains(s[i])){
                    i++;
                }
                if(j-i+1<p.second-p.first+1){
                    p.first = i; p.second = j;
                }
                mp[s[i]]--;
                if(mp[s[i]]<st[s[i]]) done--;
                i++;
            }
            j++;
        }
        if(p.second!=INT_MAX) return s.substr(p.first, p.second-p.first+1);
        return "";
    }
};
