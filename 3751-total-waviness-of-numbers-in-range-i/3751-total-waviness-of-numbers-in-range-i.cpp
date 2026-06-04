class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int count = 0;
        int val = num1;

        while(val <= num2){
            int x = val;
            int curr = -1, prev = -1, next = -1;

            while(x > 0){
                next = x%10;
                x/=10;

                if(prev != -1 && curr != -1 && next != -1){
                    count += (prev > curr && next > curr);
                    count += (prev < curr && next < curr);
                }
                
                prev = curr;
                curr = next;
            }

            val++;
        }

        return count;
    }
};