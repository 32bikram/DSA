class Solution {
public:
    vector<vector<vector<int>>> dp;
    // storing path to the end from an index, with the paths that followed till
    // here, an index can be reached with multiple paths and for each path we
    // are storing the minm value to reach end.
    int m, n;
    int dfs(int i, int j, vector<vector<int>>& grid, int t) {
        if (i >= m || j >= n)
            return INT_MAX;
        t ^= grid[i][j];
        if (dp[i][j][t] != -1)
            return dp[i][j][t];
        if (i == m - 1 && j == n - 1)
            return t;

        int right = dfs(i, j + 1, grid, t);
        int down = dfs(i + 1, j, grid, t);
        dp[i][j][t] = min(right, down);
        return dp[i][j][t];
    }
    int minCost(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        dp = vector<vector<vector<int>>>(
            m, vector<vector<int>>(n, vector<int>(1024, -1)));
        return dfs(0, 0, grid, 0);
    }
};
