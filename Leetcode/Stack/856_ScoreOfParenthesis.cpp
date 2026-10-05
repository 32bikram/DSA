class Solution {
public:
    int scoreOfParentheses(string s) {
      int depth = -1, ans = 0;
      for(char c : s){
        if(c=='(') depth++;
        else{
          if(s[i-1]==')') ans += 1 << depth; //at the maximum depth as there is no ')' before it only '('
          depth--;
        }
      }
      return ans;
};

// if we calculate the contribution of the maximum depth parenthesis we dont need to calculated outside ones. as the inside will take the depth as power of 2.
// (D(C(B(A)))) here inside A there is no bracket so 1, inside B is 1 so 2*1 = 2, inside C value comes 2 so 2*2 = 4, inside D value is 4 so 2*4 = 8.
// so instead of all these we can say maximum depth as the power of 2. so 2 the power 3 = 8. as max depth A = 3. Now just keep summing when the depth is same.
