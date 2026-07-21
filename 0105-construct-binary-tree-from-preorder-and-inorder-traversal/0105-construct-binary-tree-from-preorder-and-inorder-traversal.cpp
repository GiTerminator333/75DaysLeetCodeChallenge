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
    TreeNode* solve(vector<int>& pre, vector<int> &in, int prelo, int prehi, int inlo, int inhi){
        if(prelo > prehi) return NULL;
        //first of pre => root
        int idx = inlo;
        for(idx; idx <= inhi; idx++){
            if(in[idx] == pre[prelo]) break;
        }

        TreeNode* root = new TreeNode();
        root->val = in[idx];

        int leftCount = idx - inlo;

        root->left = solve(pre,in, prelo + 1, prelo + leftCount, inlo, idx - 1);
        root->right = solve(pre,in,prelo + leftCount + 1, prehi, idx + 1, inhi);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        return solve(preorder, inorder, 0, n-1, 0, n-1);
    }
};