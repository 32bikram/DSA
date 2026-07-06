class Solution {
public:
        int rows = 0, cols =0; //just declaration

        void bfs(int row, int col,vector<vector<char>>& grid){
            queue<pair<int,int>> q;
            q.push({row, col});
            vector<pair<int,int>> dir = {{0,-1},{0,1},{1,0},{-1,0}}; //l,r,u,d

            while(!q.empty()){
                pair<int, int> element = q.front();
                q.pop();
                for(int k = 0; k<dir.size(); k++){
                    //n stands for neighbour
                    int nrow = element.first + dir[k].first;
                    int ncol = element.second + dir[k].second;
                    if(nrow<0 || nrow>=rows || ncol<0 || ncol>=cols) continue;
                    if(grid[nrow][ncol]=='1'){
                        q.push({nrow, ncol});
                        grid[nrow][ncol] = '0';
                    }
                }
            }
            return;
        }

    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        rows = grid.size(), cols = grid[0].size();

        for(int i = 0; i<rows; i++){
            for(int j = 0; j<cols; j++){
                if(grid[i][j] == '1'){
                    islands++;
                    grid[i][j] = '0';
                    bfs(i, j, grid);
                }
            }
        }
        return islands;
    }
};

