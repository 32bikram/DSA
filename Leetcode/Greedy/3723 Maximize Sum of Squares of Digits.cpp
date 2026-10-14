class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans = "";
        if(sum>num * 9) return "";
        for(int i = 0; i<num; i++){
            int t = min(9,sum);
            ans += t+'0';
            sum = max(sum-9, 0);
        }
        return ans;
    }
};
