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
    TreeNode* solve(vector<int> &preorder, unordered_map<int, int> &map, int prelo, int prehi, int postlo, int posthi){
        if(postlo > posthi) return NULL;
        TreeNode* root = new TreeNode(preorder[prelo]); 
        if(postlo == posthi) return root;
        
        int idx = map[preorder[prelo + 1]];

        int leftCount = idx - postlo;
        root->left = solve(preorder, map, prelo + 1, prelo + leftCount + 1, postlo, idx);
        root->right = solve(preorder, map, prelo + leftCount + 2 , prehi , idx + 1, posthi - 1);

        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        unordered_map<int, int> map;
        for(int i=0; i<postorder.size(); i++){
            map[postorder[i]] = i;
        }
        int n = postorder.size();
        return solve(preorder, map, 0 , n-1, 0, n-1);
    }
};