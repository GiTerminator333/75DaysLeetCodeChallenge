class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int rbytes = 0; //remaining bytes for a sequence

        for(int val : data){
            if(rbytes == 0){
                //picking up the starting of the seq
                if( ((val >> 7) & 1) == 0){
                    rbytes = 0; //tot no of bytes == 1 ==>rbytes = 0
                }
                else if( ((val >> 5) & 7) == 6){
                    rbytes = 1;
                }
                else if( ((val >> 4) & 15) == 14){
                    rbytes = 2;
                }
                else if( ((val >> 3) & 31) == 30){
                    rbytes = 3;
                }
                else return false;
            }

            else{
                if( ((val >> 6) & 3) == 2){
                    rbytes--;
                }
                else return false;
            }
        }

        if(rbytes != 0){
            //seq left incomplete
            return false;
        }

        return true;
    }
};