class Solution {
public:
    int add(int carry, int sum){
        if(!carry) return sum;
        int nCarry = carry & sum;
        int nSum = carry ^ sum;

        return add(nCarry<<1, nSum);
    }
    int getSum(int a, int b) {
        return add(a, b);

        //basically for 1 bit xor means addition
        // but 1^1 = 0
        //so for real addition we & the same bits so that we know which bit addion produce carry
        //then we left shift those carry bits just like real multi bit addition and 
    }
};