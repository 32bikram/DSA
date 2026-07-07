class Solution {
public:
    int rows = 0, cols = 0;
    int max_area = 0;
    vector<pair<int,int>> dir = {{-1,0},{1,0},{0,-1},{0,1}}; //u,d,l,r

    void bfs(int row, int col, int &count, vector<vector<int>> &grid){
        queue<pair<int,int>> q;
        q.push({row,col});
        
        while(!q.empty()){
            row = q.front().first, col = q.front().second;
            q.pop();

            for(int i = 0; i<dir.size(); i++){
                int nrow = row + dir[i].first;
                int ncol = col + dir[i].second;
                if(nrow<0 || nrow>=rows || ncol<0 || ncol>=cols) continue;
                if(grid[nrow][ncol] == 1){
                    count++;
                    grid[nrow][ncol] = 0;
                    q.push({nrow,ncol});
                }
            }
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        rows = grid.size(), cols = grid[0].size();
        int count = 0;
        for(int i = 0; i<rows; i++){
            for(int j = 0; j<cols; j++){
                if(grid[i][j]== 1){
                    grid[i][j] = 0;
                    count++;
                    bfs(i, j, count, grid);
                }
                max_area = max(max_area, count);
                count = 0;
            }
        }
        return max_area;
    }
};

