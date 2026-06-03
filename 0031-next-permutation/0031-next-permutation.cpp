class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //finding the dip index
        int idx = -1;
        for(int i = nums.size() - 2; i>=0; i--){
            if(nums[i] < nums[i+1]){
                idx = i;
                break;
            }
        }
        
        if(idx == -1){
            //no dip -> array sorted in decreasing order
            reverse(nums.begin(), nums.end());
            return; 
        }

        //finding smallest possible no. > dip to replace the dip -> next larger number in the perm
        int sm = -1;
        for(int i = nums.size() - 1; i>idx; i--){
            if(nums[i] > nums[idx]){
                sm = i;
                break;
            }
        }

        swap(nums[sm], nums[idx]);
        //reverse the array after the dip idx after swap -> to make the remaining part smaller
        reverse(nums.begin() + idx + 1, nums.end());
    }
};