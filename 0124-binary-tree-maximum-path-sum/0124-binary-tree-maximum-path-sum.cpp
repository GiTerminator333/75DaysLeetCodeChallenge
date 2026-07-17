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
    int maxSum = INT_MIN;
    int findPathSum(TreeNode *root){
        if(!root) return 0;

        int leftSum = findPathSum(root->left);
        int rightSum = findPathSum(root->right);

        //recursive res for node as subproblem
        //take root only or either of the sum

        int res = max(root->val, root->val + max(leftSum, rightSum)); 

        //maxSum 3rd case -> pathSum of subtree is the global max
        int pathSum = root->val + leftSum + rightSum;
        maxSum = max({maxSum, res, pathSum});

        return res;
    }
    int maxPathSum(TreeNode* root) {
        findPathSum(root);
        return maxSum;
    }
};