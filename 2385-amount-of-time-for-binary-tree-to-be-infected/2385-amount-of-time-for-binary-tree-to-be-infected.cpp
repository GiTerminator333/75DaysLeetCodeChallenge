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
    TreeNode* temp = NULL;
    void findParent(unordered_map<int, TreeNode*> &parent,TreeNode* root, int &start){
        queue<TreeNode*> q;
        q.push(root);
        parent[root->val] = NULL;

        while(!q.empty()){
            TreeNode *node = q.front();
            q.pop();
            if(node->val == start) temp = node;

            if(node->left){
                q.push(node->left);
                parent[node->left->val] = node;
            }
            if(node->right){
                q.push(node->right);
                parent[node->right->val] = node;
            }
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, TreeNode*> parent;
        unordered_map<int, bool> visited;

        findParent(parent,root,start);
        

        int timer = 0;
        queue<TreeNode*> q;
        q.push(temp);

        while(!q.empty()){
            int N = q.size();
            while(N--){
                TreeNode* node = q.front();
                visited[node->val] = true;
                q.pop();

                if(node->left && visited[node->left->val] != true){
                    q.push(node->left);
                }
                if(node->right && visited[node->right->val] != true){
                    q.push(node->right);
                }
                TreeNode* pNode = parent[node->val];
                if(pNode != NULL && visited[pNode->val] != true){
                    q.push(pNode);
                }
            }

            timer++;
        }

        return timer - 1;
    }
};