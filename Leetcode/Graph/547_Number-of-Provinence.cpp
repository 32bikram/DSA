class Solution {
public:
    void DFS(int node, vector<int> &visited, vector<vector<int>> &conn, int parent){
        if(visited[node] == -2) return;
        visited[node] = -2;
        for(int i = 0; i<conn[node].size(); i++){
            if(parent == conn[node][i]) continue;
            DFS(conn[node][i], visited, conn, node);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited(n,-1);
        vector<vector<int>> conn(n); //connected nodes
        int ans = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(isConnected[i][j]==1){
                    conn[i].push_back(j);
                    conn[j].push_back(i);
                }
            }
        }
        for(int i = 0; i<visited.size(); i++){
            if(visited[i]==-1){
                ans++;
                DFS(i, visited, conn, -100);
            }
        }
        return ans;
    }
};
