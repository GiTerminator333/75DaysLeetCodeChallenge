class Solution {
public:
    void helper(vector<int> &c, vector<vector<int>> &ans, vector<int> &v, int target, int i){
        if(i == c.size()){
            if(target == 0) ans.push_back(v);
            return;
        }

        if(target >= c[i]){
            v.push_back(c[i]);
            helper(c, ans, v, target - c[i], i);
            v.pop_back();
        }

        helper(c, ans, v, target, i+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> v;

        helper(candidates, ans, v, target, 0);

        return ans;
    }
};