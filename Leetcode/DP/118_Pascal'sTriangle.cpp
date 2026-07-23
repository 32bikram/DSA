class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows);
        res[0] = {1};
        for(int i = 1; i<res.size(); i++){
            vector<int> prev_row = res[i-1];
            for(int j = 0; j<prev_row.size(); j++){
                if(j==0) res[i].push_back(prev_row[0]);
                else{
                    res[i].push_back(prev_row[j]+prev_row[j-1]);
                }
            }
            res[i].push_back(prev_row[prev_row.size()-1]);
        }
        return res;
    }
};
