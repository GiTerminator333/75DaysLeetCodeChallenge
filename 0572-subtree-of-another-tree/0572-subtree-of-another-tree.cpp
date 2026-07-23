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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root && !subRoot) return true;
        else if(!root || !subRoot) return false;
        if(root->val == subRoot->val && isSame(root, subRoot)){
            return true;
        }

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
    // bool solve(TreeNode* root, TreeNode* target) {
    //     if(!root) return false;
    //     if(root->val == target->val){
    //         if(isSame(root, target)) return true;
    //     }

    //     if(solve(root->left, target) || solve(root->right, target)) return true;
    //     return false;
    // }

    bool isSame(TreeNode* p, TreeNode* q){
        if(!p && !q) return true;
        else if(!p || !q || p->val != q->val) return false;
        return isSame(p->left, q->left) && isSame(p->right, q->right);
    }
};