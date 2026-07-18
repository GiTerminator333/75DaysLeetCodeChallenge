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
    bool isSymmetric(TreeNode* root) {
        return isMirrorDFS(root->left, root->right);
        //return isMirrorBFS(root);
    }

    bool isMirrorDFS(TreeNode* p, TreeNode* q){
        if(!p && !q) return true;
        else if(!p || !q || p->val != q->val) return false;
        return isMirrorDFS(p->left, q->right) && isMirrorDFS(p->right, q->left);
        //lst of p is identical to rst q and vice versa for mirror
    }

    typedef pair<TreeNode*,TreeNode*> p;

    bool isMirrorBFS(TreeNode* root){
        if(!root) return true;
        queue<p> q;
        q.push({root->left, root->right});

        while(!q.empty()){
            auto [node1, node2] = q.front();
            q.pop();

            if(!node1 && !node2) continue;
            else if(!node1 || !node2 || node1->val != node2->val) return false;

            q.push({node1->left, node2->right});
            q.push({node1->right, node2->left});
        }

        return true;
    }
};