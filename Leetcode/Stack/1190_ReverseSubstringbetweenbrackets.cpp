class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        for(int i = 0; i<s.size(); i++){
            if(s[i]=='('){
                st.push("");
            }
            else if(s[i]==')'){
                reverse(st.top().begin(), st.top().end());
                string temp = st.top();
                st.pop();
                if(!st.empty()) st.top()+=temp;
                else st.push(temp);
            }
            else if(st.empty()){ //"afg(jkl(mno)p)qr"
                string str = "";
                str += s[i];
                st.push(str);
            }
            else st.top()+= s[i];
        }
        return st.top();
    }
};
