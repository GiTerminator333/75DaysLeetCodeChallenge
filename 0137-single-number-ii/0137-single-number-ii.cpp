class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0; //store num with first occurence
        int twos = 0; //store num with two occurence
        // int threes = 0; //store num with three occurence <== not req

        for(int i=0; i<nums.size(); i++){
            // if( ((nums[i] ^ ones) & (~twos)) != 0){
            //     //if first occurence and no second occurence
            //     ones = nums[i];
            // }
            // else if( ((nums[i] ^ twos) & (~ones)) != 0){
            //     twos = nums[i];
            // }

            ones = (nums[i] ^ ones) & (~twos);
            twos = (nums[i] ^ twos) & (~ones);
        }

        return ones;
    }
};