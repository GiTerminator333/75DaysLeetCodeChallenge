class Solution {
public:
    int jump(vector<int>& nums) {
        int l = 0, r = 0;
        int jumpCount = 0;

        while(r < nums.size() - 1){
            int maxRange = 0; //max range of jump possible
            for(int i = l;i <= r; i++){
                maxRange = max(maxRange, i + nums[i]);
            }
            l = r + 1;
            r = maxRange;
            jumpCount++;
        } 

        return jumpCount;
    }
};