class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        vector<int> bit(32, 0); //freq of every set bit

        int totH = 0;
        for(int i=0; i<nums.size(); i++){
            int x = nums[i];
            
            for(int it = 0; it <32; it++){
                if((x&1) == 0){
                    totH += bit[it];
                }
                else{
                    int unsetFreq = (i - 0) - bit[it];
                    //fr of unset bit = length of arr -  fr of set bits;
                    totH += unsetFreq;
                    bit[it]++;
                }
                x>>=1;
            }
        }

        return totH;
    }
};