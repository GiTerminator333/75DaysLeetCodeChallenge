typedef pair<int, pair<int, int>> pi;
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        //Approach
        //start from col = 0...group the ele -> find maxi and mini -> range = [mini, maxi]
        //since the array is sorted...the only way to find the shorter range than current one is to find a minimum element from the mini 's row who's val > mini
        //so u need to add element next to mini (since arrays are sorted)
        //push it in the heap to track mini for each range
        //also update maxi each time u push next ele (as it may be > maxi)

        priority_queue<pi, vector<pi>, greater<pi>> minh;   //to track mini for each range
        // {nums[row][col], {row, col}}

        int maxi = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            maxi = max(maxi, nums[i][0]);
            minh.push({nums[i][0], {i, 0}});
        }

        int start = -1e6, end = 1e6; //to track the shortest range
        while(!minh.empty()){
            pi hTop = minh.top();
            minh.pop();

            int row = hTop.second.first;
            int col = hTop.second.second;
            int mini = hTop.first;

            if(end - start > maxi - mini){
                end = maxi;
                start = mini;
            }
            
            if(col < nums[row].size() - 1){
                minh.push({nums[row][col + 1], {row, col + 1}});
                maxi = max(maxi, nums[row][col + 1]);
            }
            else break;

        }

        return {start, end};
    }
};