class Solution {
public:
    vector<vector<int>> adj;
    string s;

    bool dfs(int u, int target, int parent, vector<int>& path) {
        path.push_back(u);

        if (u == target)
            return true;

        for (int v : adj[u]) {
            if (v == parent)
                continue;

            if (dfs(v, target, u, path))
                return true;
        }

        path.pop_back();
        return false;
    }

    bool query(int u, int v) {
        vector<int> path;
        dfs(u, v, -1, path);

        int freq[26] = {};

        for (int node : path) {
            freq[s[node] - 'a']++;
        }

        int odd = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 != 0)
                odd++;
        }

        return odd <= 1;
    }

    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string str,vector<string>& queries) {
        s = str;
        adj.assign(n, {});

        for (auto& e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> ans;

        for (string& q : queries) {
            stringstream ss(q);
            string type;
            ss >> type;

            if (type == "query") {
                int u, v;
                ss >> u >> v;
                ans.push_back(query(u, v));
            } else if (type == "update") {
                int u;
                char c;
                ss >> u >> c;
                s[u] = c;
            }
        }

        return ans;
    }
};
