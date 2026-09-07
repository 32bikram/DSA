class Solution {
public:
    vector<int> grayCode(int n) {
        vector<string> ans;
        ans.push_back("0");
        ans.push_back("1");
        n--;
        vector<string> zeropart;
        vector<string> onepart;
        while(n--){
            for(string i : ans){
                zeropart.push_back("0"+i);
            }
            for(int i = ans.size()-1; i>=0; i--){
                string s = ans[i];
                onepart.push_back("1"+s);
            }
            ans = zeropart;
            ans.insert(ans.end(), onepart.begin(), onepart.end());
            zeropart.clear();
            onepart.clear();
        }
        vector<int> result;
        for(string s : ans){
            int a = stoi(s, nullptr, 2);
            result.push_back(a);
        }
        return result;
    }
};
