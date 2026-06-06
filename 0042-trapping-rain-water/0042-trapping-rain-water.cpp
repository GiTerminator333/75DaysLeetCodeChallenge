class Solution {
public:
    int trap(vector<int>& height) {
        //right max h
        vector<int> rightMax(height.size());
        rightMax[height.size() - 1] = height[height.size() - 1];
        for(int i = height.size() - 2; i>=0; i--){
            rightMax[i] = max(height[i], rightMax[i+1]);
        }

        int leftMax = height[0];
        int totWater = 0;
        for(int i = 1; i<height.size() - 1; i++){
            if(height[i] > leftMax) leftMax = height[i];    //cal left max h
            totWater += min(leftMax, rightMax[i]) - height[i];
        }

        return totWater;
    }
};