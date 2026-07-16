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
    int findLevel(TreeNode* root, int &maxDia){
        if(root == NULL) return 0;
        int leftlevel = findLevel(root->left, maxDia);
        int rightlevel = findLevel(root->right, maxDia);

        maxDia = max(maxDia, leftlevel + rightlevel);

        return 1 + max(leftlevel, rightlevel);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDia = 0;
        int temp = findLevel(root, maxDia);

        return maxDia;
    }
};