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
    TreeNode* createBinaryTree(vector<vector<int>>& d) {
        unordered_map<int, vector<int>> mp;
        unordered_set<int> isChild;

        for(int i=0; i<d.size(); i++){
            if(mp.find(d[i][0]) == mp.end()) mp[d[i][0]] = vector<int>(2, -1);

            if(d[i][2] == 0){
                mp[d[i][0]][1] = d[i][1];   //right
            }
            else{
                mp[d[i][0]][0] = d[i][1];
            }

            isChild.insert(d[i][1]);
        }

        int root = -1;
        for(auto &[key, val] : mp){
            if(isChild.find(key) == isChild.end()){
                root = key;
                break;
            }  
        }

        //tree from the map
        TreeNode* rootNode = new TreeNode(root);
        queue<TreeNode*> q;

        q.push(rootNode);

        while(!q.empty()){
            TreeNode* cur = q.front();
            q.pop();
            if(cur == NULL) continue;

            int val = cur->val;

            int leftVal = -1, rightVal = -1;

            if(mp.find(val) != mp.end()){
                leftVal = mp[val][0]; 
                rightVal = mp[val][1];
            }

            if(leftVal != -1){
                cur->left = new TreeNode(leftVal);
            } 
            if(rightVal != -1){
                cur->right = new TreeNode(rightVal);
            } 
            
            q.push(cur->left);  
            q.push(cur->right);
        }

        return rootNode;
    }
};