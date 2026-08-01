class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.size());
        bool flag = false;

        if(s[0] == '0') return 0;
        else dp[0] = 1;
        if(s[1]=='0') dp[1] = dp[0];
        else dp[1] = dp[0]+2; //or akta, ager tar akta, pair akta;

        for(int i = 2; i<s.size(); i++){
            if(s[i]==0) return 0;

            if(i+1<s.size() && s[i+1]!=0){
                if(flag == true){
                    dp[i] = dp[i-1]+2; //one of its own, other for pair
                    flag = false;
                }
                else{
                    dp[i] = dp[i-1]+1;
                    flag = true;
                }
            }

            else if(i+1<s.size() && s[i+1]==0){
                if((s[i]-'0')*10 + s[i+1] - '0' <= 26){
                    dp[i] = dp[i-1]; // 0 er ager tar jnno
                    dp[i+1] = dp[i]+1; //0 er jnno
                    flag = false; //since o zero r sathe pair banai nise akhon abar notun kore suru
                    i++; //0 skip
                }
                else return 0;
            }

            else if(i+1 == s.size()){
                if(flag == false) dp[i] = dp[i-1] + 1;
                else dp[i] = dp[i-1]+2; //one of its own, other for pair
            }
        }
        return dp[s.size()-1];
    }
};
