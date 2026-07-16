class Solution {
public:
    bool DFS(int a, vector<int>& visited, vector<vector<int>> &prede, int parent){
        if(parent == a) return false; // in case single node loop like 0<-->0 0 is connencted to itself
        if(visited[a] == -2) return false;   //return case if node was already visited
        visited[a] = -2;  //marking the node visited
        for(int i = 0; i<prede[a].size(); i++){
            if(parent == prede[a][i]) continue; //in case current node is parent we skip it
            if(!DFS(prede[a][i], visited, prede, a)) return false;
        }
        return true;

    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.empty() && n == 1) return true;
        vector<int> visited(n, -1);
        vector<vector<int>> prede(n);
        for(int i = 0; i<edges.size(); i++){
            prede[edges[i][0]].push_back(edges[i][1]); //so in case of {0,1} binding 1 a prede of 0
            prede[edges[i][1]].push_back(edges[i][0]); // binding 0 as prede of 1
        }
        for(int i = 0; i<edges.size(); i++){
            if(visited[i]!=-2 && !prede[i].empty()){
                if(!DFS(i, visited, prede, -100)) return false;
                break; //we are only gonna explore a single node, if its a tree we could traverse the
                //whole tree with that single node, if its segmented then we will only traverse a portion
            }
        }
        for(int i = 0; i<visited.size(); i++){
            if(visited[i] == -1) return false;  //unvisited note, segment tree
        }
        return true;
    }
};
