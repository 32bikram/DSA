
class Solution {
public:
    long long dfs(vector<vector<int>>& grid, int k, int i, int j) {
        if (grid[i][j] == 0 || grid[i][j] == -1)
            return 0;

        vector<vector<int>> dir = {
            {-1, 0}, {0, -1}, {1, 0}, {0, 1}
        };

        long long t = grid[i][j];
        grid[i][j] = -1;

        for (auto vec : dir) {
            int x = i + vec[0];
            int y = j + vec[1];

            if (x < 0 || x >= grid.size() ||
                y < 0 || y >= grid[0].size())
                continue;

            t += dfs(grid, k, x, y);
        }

        return t;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        int ans = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0 || grid[i][j] == -1)
                    continue;

                long long sum = dfs(grid, k, i, j);

                if (sum % k == 0)
                    ans++;
            }
        }

        return ans;
    }
};
