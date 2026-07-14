class Solution {
public:
    int DFS(pair<int, vector<int>> &node, vector<pair<int, vector<int>>> &graph){
        if(node.first == 0) return 1;    //no preq
        if(node.first == -2) return 0;   //deadlock
        node.first = -2;
        int cnt = 0;
        for(int i = 0; i<node.second.size(); i++){
            cnt += DFS(graph[node.second[i]], graph);
        }
        if (cnt == node.second.size()){
            node.first = 0;
            return 1;
        }
        return 0;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<pair<int, vector<int>>> graph (numCourses);
        for(int i = 0; i<prerequisites.size(); i++){
            graph[prerequisites[i][0]].first = -1;
            graph[prerequisites[i][0]].second.push_back(prerequisites[i][1]);
        }
        int cnt = 0;
        for(int i = 0; i<graph.size(); i++){
            cnt += DFS(graph[i], graph);
        }
        if(cnt == graph.size()) return true;
        return false;
    }
};
