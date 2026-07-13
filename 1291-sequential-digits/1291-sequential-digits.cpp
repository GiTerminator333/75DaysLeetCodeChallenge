class Solution {
    vector<string> dict = {"12", "123","1234", "12345", "123456", "1234567", "12345678", "123456789"};
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> v;
        int i = 0;
        while(i<dict.size()){
            string temp = dict[i];
            while(stoi(temp) <= high){
                if(stoi(temp) >= low) v.push_back(stoi(temp));
                if(temp.back() =='9') break;

                for(char &c : temp){
                    c++;
                }
            }

            i++;
        }

        return v;
    }
};