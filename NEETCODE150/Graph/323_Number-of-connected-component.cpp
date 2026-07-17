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
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> visited(n, -1);
        vector<vector<int>> conn(n); //connected nodes
        int ans = 0;
        for(int i = 0; i<edges.size(); i++){
            conn[edges[i][1]].push_back(edges[i][0]);
            conn[edges[i][0]].push_back(edges[i][1]);
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
