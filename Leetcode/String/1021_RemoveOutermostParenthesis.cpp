class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st; string ans = "";
        for(int i = 0; i<s.size(); i++){
            char c = s[i];
            if(s[i]=='('){
                if(!st.empty()) ans+="(";
                st.push('(');
            }
            else{
                if(st.size()==1){
                    st.pop();
                }
                else{
                    st.pop();
                    ans += ")";
                }
            }
        }
        return ans;
    }
};
