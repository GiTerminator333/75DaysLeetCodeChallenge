class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans(nums.size(), pivot);
        int less = 0, pivotCount = 0;

        for(int i=0; i<nums.size(); i++){
            if(nums[i] < pivot){
                ans[less] = nums[i];
                less++;
            }
            else if(nums[i] == pivot){
                pivotCount++;
            }
        }
        int j = less + pivotCount;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] > pivot){
                ans[j] = nums[i];
                j++;
            }
            else continue;
        }
        return ans;
    }
};