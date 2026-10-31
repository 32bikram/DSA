class Solution {
public:
    vector<vector<pair<int,int>>> dp;
    int m, n, mod = 1e9 + 7;
    int dfs(vector<vector<int>> &grid, int i, int j, char prev){

        if(i<0 || i>=n || j<0 || j>=m) return 0;
        if(i==n-1 && j==m-1) return 1;

        if(grid[i][j]==0 && dp[i][j].first!=-1) return dp[i][j].first;
        else if((grid[i][j]==1 && prev == 'd') && dp[i][j].first!=-1) return dp[i][j].first;
        else if((grid[i][j]==1 && prev == 'r') && dp[i][j].second!=-1) return dp[i][j].second;

        int total = 0;
        if(grid[i][j]==1){
            if(prev=='d'){
                total += dfs(grid, i, j+1, 'r');
                total %= mod;
            }
            else total += dfs(grid, i+1, j, 'd');
            total %= mod;
        }

        else{
            total += dfs(grid, i, j+1, 'r');
            total %= mod;
            total += dfs(grid, i+1, j, 'd');
            total %= mod;
        }
        
        if(grid[i][j]==0) dp[i][j] = {total, total};
        else if(prev == 'd') dp[i][j].first = total; //came from top
        else dp[i][j].second = total; //came from left
        return total;
    }
    int uniquePaths(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        dp = vector<vector<pair<int,int>>> (n, vector<pair<int,int>> (m, {-1,-1})); //from top, from left
        //for 1s there will be two paths if, source came from top or left?
        return dfs(grid, 0, 0, 'd');
    }
};
