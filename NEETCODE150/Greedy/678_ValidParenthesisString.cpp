class Solution {
public:
    bool checkValidString(string s) {
        stack<int> l_paren;
        stack<int> star;
        for(int i = 0; i<s.size(); i++){
            if(s[i]=='(') l_paren.push(i);
            else if(s[i]=='*') star.push(i);
            else{
                if(!l_paren.empty()) l_paren.pop();
                else if(!star.empty()) star.pop();
                else return false;
            }
        }
        if(l_paren.size()>star.size()) return false;
        int i =l_paren.size();
        while(i--){
            if(l_paren.top()<star.top()){
                l_paren.pop();
                star.pop();
            }
            else return false;
        }
        return true;
    }
};
