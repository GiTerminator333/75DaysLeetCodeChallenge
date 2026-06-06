class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> leftSum(nums.size());
        // vector<int> rightSum(nums.size());
        leftSum[0] = 0;
        for(int i=1; i<nums.size(); i++){
            leftSum[i] = leftSum[i-1] + nums[i - 1]; 
        }
        int sum = leftSum[nums.size() - 1] + nums[nums.size() - 1];

        for(int i=0; i<nums.size(); i++){
            nums[i] = abs(leftSum[i] - (sum - leftSum[i] - nums[i]));
        }

        return nums;
    }
};