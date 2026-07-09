/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> visited;

    void dfs(Node* temp, Node* original){
        if(original == NULL) return;
        int n = original->neighbors.size(); //original->neighbors is the vector for the node
        int t = 0;
        for(int i = 0; i<n; i++){
            t = original->neighbors[i]->val;

            if(visited.contains(original->neighbors[i])==true){ //in case of the node is already build, we just push
            Node* temp2 = visited[original->neighbors[i]];
            temp->neighbors.push_back(temp2); //building temporary node's neighbor array
            }
            else{  //if not created already, we create and explore
                Node* temp2 = new Node(t);
                temp->neighbors.push_back(temp2);
                visited[original->neighbors[i]] = temp2;
                dfs(temp2, original->neighbors[i]);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        Node* ans = new Node(node->val);
        visited[node] = ans;
        dfs(ans, node);
        return ans;
    }
};

