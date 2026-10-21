class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        bool flag = true;

        for(int i = 1; i < n; i++) {
            if(s[i] < s[i - 1]) {
                flag = false;
                break;
            }
        } //check if sorted

        if(flag) {
            return 0;
        }

        if(n == 2) {
            return -1;
        } // size 2 but unsorted, cant be sorted

        char minChar = 'z';
        char maxChar = 'a';

        for(char ch : s) {
            minChar = min(minChar, ch);
            maxChar = max(maxChar, ch);
        }

        if(minChar == s[0] || maxChar == s[n - 1]) {
            return 1;
        } // just sort the front except last, or the back except first

        for(int i = 1; i < n - 1; i++) {
            if(s[i] == minChar || s[i] == maxChar) {
                return 2;
            }
        } // in middle so minm 2 sort must needed

        return 3; //max at first as well as min at last as
        //if one of them is still in middle we would need 2 sort
    }
};
