class Solution {
public:
    void BFS(vector<vector<int>>& grid){
        queue<pair<int,int>> q;
        vector<vector<int>> dir {{0,-1},{0,1},{1,0},{-1,0}}; //lrud
        int rows = grid.size(), cols = grid[0].size();

        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){
                if(grid[i][j] == 0) q.push({i,j});
                else grid[i][j] = -1;
            }
        }

        while(!q.empty()){
            pair<int,int> cell = q.front();
            q.pop();
            int row = cell.first, col = cell.second;
            int nrow, ncol;
            for(int i = 0; i<dir.size(); i++){
                nrow = row + dir[i][0], ncol = col + dir[i][1];
                if(nrow<0 || nrow>= rows || ncol<0 || ncol>=cols) continue;
                if(grid[nrow][ncol]==-1){
                    grid[nrow][ncol] = grid[row][col] + 1;
                    q.push({nrow,ncol});
                }
            }
        }
    }
     vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
            BFS(mat);
            return mat;
     }
 };

