class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans;
        string str = "";

        for(int i = 0; i<n; i++){
            str += ".";
        }
        ans.push_back(str);
        str = "";
        
        for(int i = 0; i<n-1; i++){
            str += "#";
        }
        str += ".";
        for(int i = 1; i<m; i++){
            ans.push_back(str);
        }
        return ans;
    }
};
