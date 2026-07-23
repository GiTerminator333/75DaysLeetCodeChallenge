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
    bool isCompleteTree(TreeNode* root) {
        //DFS
        //count tot nodes
        //consider an array 0 based indexing, index all nodes including null
        //if indexCount >= totCount, not complete
        if(!root) return true;

        int totCount = countNodes(root);
        return isComplete(root, 0, totCount);
    }

    bool isComplete(TreeNode* root, int index, int totCount){
        if(!root) return true;
        if(index >= totCount) return false;

        return isComplete(root->left, 2*index+1, totCount) && isComplete(root->right, 2*index+2, totCount);
    }

    int countNodes(TreeNode* root){
        if(!root) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};