class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st; int ans = 0;
        st.push(-1); //we need a boundary for ()() 0,1,2,3 there is nothing to subtract from index 1; 
        for(int i = 0; i<s.size(); i++){
            if(s[i]=='(') st.push(i);
            else{
                st.pop();
                if(st.empty()) st.push(i); //reset whenever a valid sequence ended
                else{
                    ans = max(ans, i-st.top());
                }
            }
        }
        return ans;
    }
};
