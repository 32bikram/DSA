class Solution {
public:
    unordered_map<char, string> mp = {{'2', "abc"},{'3',"def"},{'4',"ghi"},
    {'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};

    vector<string> ans;

    void back(int idx, string digits, string &s){
        if(idx == digits.size() && s.size()>0){
            ans.push_back(s);
            return;
        }

        string chars = mp[digits[idx]];
        for(int i = 0; i<chars.size(); i++){
            s += chars[i];
            back(idx+1, digits, s);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        string s = "";
        back(0, digits, s);
        return ans;
    }
};

