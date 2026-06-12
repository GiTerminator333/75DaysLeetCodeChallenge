typedef pair<int, pair<int, int>> pi;
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<pi> maxh;
        priority_queue<pi, vector<pi>, greater<pi>> minh;

        for(int i=0; i<nums.size(); i++){
            minh.push({nums[i][0], {i, 0}});
            maxh.push({nums[i][0], {i, 0}});
        }

        int minIdx = -1, maxIdx = -1;
        int minDiff = INT_MAX;
        vector<int> ans;

        while(!minh.empty()){
            pi mini = minh.top();
            pi maxi = maxh.top();

            minh.pop();

            int lowerLimit = mini.first, upperLimit = maxi.first;
            if(minDiff > upperLimit - lowerLimit){
                minDiff = upperLimit - lowerLimit;
                ans = {lowerLimit, upperLimit};
            }

            int row = mini.second.first;
            int col = mini.second.second;

            if(col < nums[row].size() - 1){
                minh.push({nums[row][col + 1], {row, col + 1}});
                maxh.push({nums[row][col + 1], {row, col + 1}});
            }
            else break;
        }

        return ans;
    }
};