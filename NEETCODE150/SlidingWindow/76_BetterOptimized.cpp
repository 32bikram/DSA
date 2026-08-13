class Solution {
public:
    string minWindow(string s, string t) {
        int for_t[128] = {0};
        int for_s[128] = {0};
        int unique = 0;
        for(char c : t){
            if(for_t[c]==0) unique++;
            for_t[c]++;
        }
        pair<int,int> p = {0,INT_MAX-1}; //INT_MAX-1 karon jodi 0 index theke suru hoy then max-0+1 overflow korbe tai +1 korar jayga rakhlam
        int done = 0;
        int i = 0, j = 0;
        while(j<s.size()){
                for_s[s[j]]++;
                if(for_s[s[j]]==for_t[s[j]]) done++;

            while(done==unique && i<s.size()){
                while(for_t[s[i]!=0]){
                    i++;
                }
                if(j-i+1<p.second-p.first+1){
                    p.first = i; p.second = j;
                }
                for_s[s[i]]--;
                if(for_s[s[i]]<for_t[s[i]]) done--;
                i++;
            }
            j++;
        }
        if(p.second!=INT_MAX-1) return s.substr(p.first, p.second-p.first+1);
        return "";
    }
};
