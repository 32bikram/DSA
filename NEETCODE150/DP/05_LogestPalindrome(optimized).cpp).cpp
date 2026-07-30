class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size()==1) return s;

        string ans = "";
        int resl = 0, resr = 0;
        int l = 0, r = 0;

        for(int i = 0; i<s.size(); i++){

            l = i-1, r = i+1; 
            while(l>=0 && r<s.size()){
                if(s[l]==s[r]){
                    if(r-l > resr-resl) resl = l, resr = r;
                    l--; r++;
                }
                else break;
            }

            l = i, r = i+1;
            while(l>=0 && r<s.size()){
                if(s[l]==s[r]){
                    if(r-l>resr-resl) resl = l, resr = r;
                    l--; r++;
                }
                else break;
            }
        }
        
        return s.substr(resl, resr-resl+1);
    }
};
