class Solution {
public:
    vector<int> ans;
    set<int> st;
    bool DFS(pair<int, vector<int>> &node, vector<pair<int, vector<int>>> &graph){
        if(node.first == 0) return true;    //no preq
        if(node.first == -2) return false;   //deadlock
        node.first = -2;
        for(int i = 0; i<node.second.size(); i++){
            if(!DFS(graph[node.second[i]], graph)) return false;
            if(!st.contains(node.second[i])){
                ans.push_back(node.second[i]);
                st.insert(node.second[i]);
            }  
        }
        node.first = 0;
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<pair<int, vector<int>>> graph (numCourses);

        for(int i = 0; i<prerequisites.size(); i++){
            graph[prerequisites[i][0]].first = -1;
            graph[prerequisites[i][0]].second.push_back(prerequisites[i][1]);
        }

        for(int i = 0; i<graph.size(); i++){
            if(!DFS(graph[i], graph)) return {};
            if(!st.contains(i)){
                ans.push_back(i);
                st.insert(i);
            } 
        }

        for(int i = 0; i<graph.size(); i++){
            if(!st.contains(i) && graph[i].second.empty()){
                ans.push_back(i);
                st.insert(i);
            }
        } //for the unexplored node that has no preq

        if(ans.size()==numCourses) return ans;
        return {};
    }
};
// i wanted to write vector instead of set, i am just feeling lazy today maybe later
