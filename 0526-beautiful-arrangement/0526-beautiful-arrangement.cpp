class Solution {
public:
    int helper(vector<int> &v, int start){
        if(start == v.size()){
            return 1;
        }

        int count = 0;
        for(int i=start; i<v.size(); i++){
            int x = start + 1;
            if( x%v[i] == 0 || v[i]%x == 0 ){
                swap(v[start], v[i]);
                count +=helper(v, start + 1);
                swap(v[start], v[i]);
            }
        }

        return count;
    }
    int countArrangement(int n) {
        vector<int> v;
        for(int i=1; i<=n; i++){
            v.push_back(i);
        }

        return helper(v, 0);
    }
};