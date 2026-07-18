class Solution {
public:
    bool DFS(int node, vector<int> &visited, vector<vector<int>> &conn, int parent){
        if(visited[node] == -2) return true;
        visited[node] = -2;
        for(int i = 0; i<conn[node].size(); i++){
            if(conn[node][i] == parent) continue;
            if(DFS(conn[node][i], visited, conn, node)) return true;
            //true if loop occurs false if loop doesnt
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        //number of min edges without causing a loop is n-1; since there is
        //n edges given, and contain a loop with by adding one so nodes = (n-1)+1 = n;
        //doing n+1 since the nodes start from 1 not 0
        vector<vector<int>> conn(n+1);
        for(int i = 0; i<edges.size(); i++){
            conn[edges[i][0]].push_back(edges[i][1]);
            conn[edges[i][1]].push_back(edges[i][0]);
            vector<int> visited(n+1, -1); //gotta rest after every edge call
            if(DFS(edges[i][0], visited, conn, -100)) return {edges[i][0], edges[i][1]};
        }

        return {};
    }
};
