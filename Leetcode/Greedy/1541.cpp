class Solution {
public:
    int minInsertions(string s) {
        //closing asle tar ager akta opening ke consume kortei lagbe
        //closing manei consume nba thakle banai consume
        //cause closeing por opening, tar por abar closing asle sei closing samner oopening use korte parbe na like ()()))
        int ans = 0, open = 0;
        for(int i = 0; i<s.size(); i++){
            if(s[i]=='(') open++;
            else{
                if(i+1<s.size() && s[i+1]==')') i++; //just skip;
                else ans++;

                if(open<=0) ans++; //open nai closing aise porlo
                else open--; //age open chilo consume korlam
            }
        }
        return 2*open + ans;
    }
};
