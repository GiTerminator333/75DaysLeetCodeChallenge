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
    int solve(TreeNode* root){
        if(!root) return INT_MAX;
        if(root->left == NULL && root->right == NULL) return 1;

        int ld = solve(root->left);
        int rd  = solve(root->right);

        int depth = 1 + min(ld, rd);
        return depth;   
    }
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        return solve(root);   
    }
};