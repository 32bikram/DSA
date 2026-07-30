class Solution {
public:
    string palindrome(int l, int r, string s){
        string temp = "";
            while(l>=0 && r<s.size()){
                if(s[l]==s[r]){
                    temp = s.substr(l, r-l+1);
                    l--; r++;
                }
                else break;
            }
        return temp;
    }
    
    string longestPalindrome(string s) {
        if(s.size()==1) return s;

        string ans = "";
        for(int i = 0; i<s.size(); i++){

            string temp = palindrome(i-1,i+1, s);
            if(temp.size()>ans.size()) ans = temp;

            temp = palindrome(i, i+1, s);
            if(temp.size()>ans.size()) ans = temp;

            temp = palindrome(i-1,i,s);
            if(temp.size()>ans.size()) ans = temp;
        }
        
        if(ans.size()==0){ //no palindrome so pushing a single char
            ans += s[0];
            return ans;
        }
        return ans;
    }
};
