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
    int ans = INT_MIN;
    int dfs(TreeNode *root){
        int s1 = 0, s2 = 0;
        if(root==NULL) return 0;
        s1 = dfs(root->left);
        s2 = dfs(root->right);
        if(s1<=0 && s2>0){
            ans = max(ans,s2+root->val);
            return s2+root->val;
        }
        else if(s1>0 && s2<=0){
            ans = max(ans,s1+root->val);
            return s1+root->val;
        }
        else if(s1<=0 && s2<=0){
            ans = max(ans,root->val);
            return root->val;
        }
        else{
            int s3 = max(s1,s2);
            ans = max(ans,s1+s2+root->val);
            return s3+root->val;
        }
        
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
