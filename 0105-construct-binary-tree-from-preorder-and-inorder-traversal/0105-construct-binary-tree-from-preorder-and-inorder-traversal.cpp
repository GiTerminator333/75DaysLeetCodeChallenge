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
    TreeNode* solve(vector<int>& pre, unordered_map<int, int> &map, int prelo, int prehi, int inlo, int inhi){
        if(prelo > prehi) return NULL;
        //first of pre => root
        //improved search efficiency using map
        TreeNode* root = new TreeNode(pre[prelo]);
        int idx = map[root->val];
        int leftCount = idx - inlo;

        root->left = solve(pre, map, prelo + 1, prelo + leftCount, inlo, idx);
        root->right = solve(pre, map, prelo + leftCount + 1, prehi, idx + 1, inhi);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();

        unordered_map<int, int> map;
        for(int i=0; i<inorder.size(); i++){
            map[inorder[i]] = i;
        }
        return solve(preorder, map, 0, n-1, 0, n-1);
    }
};