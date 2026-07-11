class Solution {
public:
    void BFS(vector<vector<int>> &grid){
        queue<pair<int,int>> q;
        vector<vector<int>> dir {{0,-1},{0,1},{-1,0},{1,0}};
        int rows = grid.size(), cols = grid[0].size();
        int nrow, ncol;
        for(int i = 0; i<rows; i++){
            for(int j = 0; j<cols; j++){
                if(grid[i][j]==2) {
                    grid[i][j] = 0;
                    q.push({i,j});
                }
                else if(grid[i][j]==1) grid[i][j] = -1; 
                //as time could be 1 minute so moding the time to 1 minute and haveing
                //fresh fruit in cell as 1 will become confusing
                else grid[i][j] = INT_MAX;
                //converting the problem to treasure and gates
            }
        }
        while(!q.empty()){
            pair<int,int> cell = q.front();
            q.pop();
            for(int i = 0; i<dir.size(); i++){
                nrow = cell.first + dir[i][0];
                ncol = cell.second + dir[i][1];
                if(nrow<0 || nrow>=rows || ncol<0 || ncol>=cols) continue;
                if(grid[nrow][ncol]==-1){
                    grid[nrow][ncol] = (grid[cell.first][cell.second])+1;
                    q.push({nrow,ncol});
                }
            }
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        BFS(grid);
        int ans = INT_MIN;
        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){
                if(grid[i][j]==-1) return -1; //mane akta hoile kola untouched, poche nai ba pochbe na tai timer nai, -1 hoye ache
                if(grid[i][j]!=INT_MAX) ans = max(grid[i][j], ans);
            }
        }
        if(ans == INT_MIN) return 0; //mane kono pocha kola e nai kono valo kolao nai
        return ans;
    }
};

