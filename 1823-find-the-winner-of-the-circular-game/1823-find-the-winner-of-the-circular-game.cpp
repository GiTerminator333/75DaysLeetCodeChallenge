class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> v(n);
        for(int i=0; i<n; i++) v[i] = i + 1;

        josephus(v,k, 0);
        return v[0];
    }

    void josephus(vector<int> &v, int &k, int idx){
        if(v.size() == 1) return;
        idx = (idx + k - 1)%v.size();
        v.erase(v.begin() + idx);
        josephus(v, k, idx);
    }
};