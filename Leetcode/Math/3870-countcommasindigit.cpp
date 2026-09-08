class Solution {
public:
    int countCommas(int n) {
        return max(n-999, 0);
        /*only 0 - 999 digits wont need any decimal
        but after 999 all digits would need decimal
        like 9,999 would need 9000 decimal
        for 1,000 to 1,999 = 1000 decimal
        for 2000 to 2999 = 1000 decimal
        .....
        .....
        till 9000 to 9990 total (1000)*9 decimal points
        */
    }
};
