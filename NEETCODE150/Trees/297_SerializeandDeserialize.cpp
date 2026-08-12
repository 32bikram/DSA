/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
   public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        if (root == NULL) return "N";
        s += to_string(root->val);
        s += ',';
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                TreeNode* temp = q.front();
                q.pop();
              
                if (temp->left != NULL) {
                    s += to_string(temp->left->val);
                    s += ',';
                    q.push(temp->left);
                } else
                    s += "N,";
              
                if (temp->right != NULL) {
                    s += to_string(temp->right->val);
                    s += ',';
                    q.push(temp->right);
                } else
                    s += "N,";
              
            }
        }
        int i = s.size() - 1;
        while (s[i] == 'N' && s[i] == ',') i--;
        return s.substr(0, i + 1);
    }

    // Decodes your encoded data to tree.
    TreeNode* build(string& data, int idx) {
        if (data[0] == 'N') return NULL;
        queue<TreeNode*> q;
        TreeNode* temp = new TreeNode();
        if (data[0] == '-') {
            int a=0;
            idx = 1;
            while(data[idx]!=','){
                a = a*10+data[idx]-'0';
                idx++;
            }
            temp->val = (-1 * a);
            idx++;
        } else
            {
                int a=0;
                while(data[idx]!=','){
                a = a*10+data[idx]-'0';
                idx++;
                }
                temp->val = a;
                idx++;
            }
        TreeNode* res = temp;
        if (idx >= data.size()) return res;
        q.push(temp);
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                temp = q.front();
                q.pop();

                if (data[idx] != 'N') {
                    TreeNode* temp2 = new TreeNode();
                    if (data[idx] == '-') {
                        int a=0;
                        idx++;
                        while(data[idx]!=','){
                            a = a*10+data[idx]-'0';
                            idx++;
                        }
                        temp2->val = (-1 * a);
                        idx++;
                    } else{
                        int a=0;
                        while(data[idx]!=','){
                        a = a*10+data[idx]-'0';
                        idx++;
                        }
                        temp2->val = a;
                        idx++;
                    }
                    temp->left = temp2;
                    q.push(temp2);
                } else {
                    temp->left = NULL;
                    idx+=2;
                }
                if (idx >= data.size()) return res;
                if (data[idx] != 'N') {
                    TreeNode* temp3 = new TreeNode();
                    if (data[idx] == '-') {
                        int a=0;
                        idx++;
                        while(data[idx]!=','){
                            a = a*10+data[idx]-'0';
                            idx++;
                        }
                        temp3->val = (-1 * a);
                        idx++;
                    } else{
                        int a=0;
                        while(data[idx]!=','){
                        a = a*10+data[idx]-'0';
                        idx++;
                        }
                        temp3->val = a;
                        idx++;
                    }
                    temp->right = temp3;
                    q.push(temp3);
                } else {
                    temp->right = NULL;
                    idx+=2; //for N and ,
                }
                if (idx >= data.size()) return res;
            }
        }
        return res;
    }

    TreeNode* deserialize(string data) { return build(data, 0); }
};
