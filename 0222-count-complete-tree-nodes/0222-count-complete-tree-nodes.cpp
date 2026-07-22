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
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int res = 0;
        int nodeCount = 1;  //node count for complete filled lvl
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty() && q.size() == nodeCount){
            int N = q.size();
            while(N--){
                TreeNode* node = q.front();
                q.pop();

                if(node->left) q.push(node->left); 
                if(node->right) q.push(node->right); 
            }

            res += nodeCount;
            nodeCount <<= 1;
        }

        return res += q.size();
    }
};