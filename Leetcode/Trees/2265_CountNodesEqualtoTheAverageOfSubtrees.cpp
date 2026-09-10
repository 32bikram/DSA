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
class Solution {
public:
    int count = 0;
    pair<int,int> dfs(TreeNode* root){
        if(!root) return {0,0}; //sum of child's values, number of children
        pair<int,int> l = dfs(root->left);
        pair<int,int> r = dfs(root->right);
        int no_of_nodes = l.second+r.second+1;
        int sum = root->val+l.first+r.first;
        int avg = sum/no_of_nodes;
        if(root->val==avg) count++;
        return {sum, no_of_nodes};
    }

    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return count;
    }
};
