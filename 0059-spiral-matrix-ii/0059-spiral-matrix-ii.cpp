class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> v(n, vector<int>(n));
        int minr = 0, minc = 0;
        int maxr = n-1, maxc = n-1;

        int val = 1;

        while(minr <= maxr && minc <= maxc){
            //right
            for(int i = minc; i <= maxc; i++){
                v[minr][i] = val++;
            }
            minr++;
            if(minr > maxr || minc > maxc) break;

            //down
            for(int i = minr; i <= maxr; i++){
                v[i][maxc] = val++;
            }
            maxc--;
            if(minr > maxr || minc > maxc) break;

            //left
            for(int i = maxc; i >= minc; i--){
                v[maxr][i] = val++;
            }
            maxr--;
            if(minr > maxr || minc > maxc) break;
            
            //up
            for(int i = maxr; i >= minr; i--){
                v[i][minc] = val++;
            }
            minc++;
            if(minr > maxr || minc > maxc) break;
        }

        return v;
    }
};