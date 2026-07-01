class Solution {
public:
    vector<string> ans;
    void backtracking(int op, int cp, string &str, int n){
        if((op == cp) && (op == n)){
            ans.push_back(str);
            return;
        }
        if(op<n){
            op++;
            str += '(';
            backtracking(op, cp, str, n);
            str.pop_back();
            op--;
        }
        if(cp<op){
            cp++;
            str += ')';
            backtracking(op, cp, str, n);
            str.pop_back();
            cp--;
        }
    } 

    vector<string> generateParenthesis(int n) {
        int op = 0, cp = 0;
        string str = "";
        backtracking(op, cp, str, n);
        return ans;
    }
};

