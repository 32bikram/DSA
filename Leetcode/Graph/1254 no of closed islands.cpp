class Solution {
public:
    int visited = 2;
    int dfs(vector<vector<int>>& grid, int i, int j){
        if(grid[i][j]==1 || grid[i][j]==visited) return 1;
        vector<vector<int>> dir = {{0,-1}, {1,0}, {0,1}, {-1,0}};
        grid[i][j] = visited;
        int a = i, b = j, k = 1;
        for(vector<int> vec : dir){
            a += vec[0];
            b += vec[1];
            if(a<0 || a>=grid.size() || b<0 || b>=grid[0].size()){
                if(k>0) k = -1;
            }
            else if(dfs(grid, a, b)==-1) k = -1;
            //nothing to do if it returns 1
            a=i, b=j;
        }
        return k;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){
                if(grid[i][j]==1 || grid[i][j]==visited) continue;
                else if(dfs(grid, i, j)==1) ans++;
            }
        }
        return ans;
    }
};
