class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> change(2, 0); //5,10

        for(int i=0; i<bills.size(); i++){
            if(bills[i] == 5) change[0]++;
            else if(bills[i] == 10){
                change[1]++;
                if(change[0]) change[0]--;
                else return false;
            }
            else{
                if(change[1] && change[0]){
                    change[0]--;
                    change[1]--;
                }
                else if(change[0] >= 3){
                    change[0] -= 3;
                }
                else return false;
            }
        }

        return true;
    }
};