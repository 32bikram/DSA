class Solution {
public:
    int rows, cols;
    vector<vector<int>> dir {{0,-1},{0,1},{1,0},{-1,0}};
    void DFS(vector<vector<int>>& heights, vector<vector<int>> &sea, int row, int col, int prev){
        if(sea[row][col] == 1 || heights[row][col]<prev) return;
        sea[row][col] = 1;
        int nrow, ncol;
        for(int i = 0; i<dir.size(); i++){
            nrow = row + dir[i][0], ncol = col + dir[i][1];
            if(nrow<0 || nrow>=rows || ncol<0 || ncol>=cols)  continue;
            DFS(heights, sea, nrow, ncol, heights[row][col]);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        rows = heights.size(), cols = heights[0].size();
        vector<vector<int>> p(rows, vector<int>(cols, 0));
        vector<vector<int>> a(rows, vector<int>(cols, 0));

        for(int i = 0; i<cols; i++){ //first row(pac)
            DFS(heights, p, 0, i, INT_MIN);
        }

        for(int i = 0; i<rows; i++){ //first col(pac)
            DFS(heights, p, i, 0, INT_MIN);
        }

        for(int i = 0; i<cols; i++){ //last row(atl)
            DFS(heights, a, rows-1, i, INT_MIN);
        }

        for(int i = 0; i<rows; i++){ //last col(atl)
            DFS(heights, a, i, cols-1, INT_MIN);
        }

        vector<vector<int>> ans;
        for(int i = 0; i<rows; i++){
            for(int j = 0; j<cols; j++){
                if(p[i][j]==1 && a[i][j]==1) ans.push_back({i,j});
            }
        }
        return ans;
    }
};
