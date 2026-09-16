class Solution {
public:
    string convert(string s, int numRows) {
        if(s.size()==1 || s.size()==2 || numRows==1) return s;
        vector<string> vec(numRows,"");
        int t = 0;
        bool increasing = true;
        for(int i = 0; i<s.size(); i++){
            if(t>=numRows && increasing){
                t-=2;
                increasing = false;
            }
            else if(t<0){
                increasing = true;
                t+=2;
            }
            vec[t]+= s[i];
            if(increasing) t++;
            else t--;
        }
        string ans = "";
        for(string s : vec) ans += s;
        return ans;
    }
};
