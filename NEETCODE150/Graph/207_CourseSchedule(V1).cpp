class Solution {
public:
    bool DFS(pair<int, vector<int>> &node, vector<pair<int, vector<int>>> &graph){
        if(node.first == 0) return true;    //no preq
        if(node.first == -2) return false;   //deadlock
        node.first = -2;
        for(int i = 0; i<node.second.size(); i++){
            if(!DFS(graph[node.second[i]], graph)) return false;
        }
        node.first = 0;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<pair<int, vector<int>>> graph (numCourses);
        //use two data structure when you solve next like i did for last questions in graph
        for(int i = 0; i<prerequisites.size(); i++){
            graph[prerequisites[i][0]].first = -1;
            graph[prerequisites[i][0]].second.push_back(prerequisites[i][1]);
        }
        for(int i = 0; i<graph.size(); i++){
            if(!DFS(graph[i], graph)) return false;
        }
        return true;
    }
};
//porasun kor laura
