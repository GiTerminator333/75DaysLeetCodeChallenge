class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int lo = 0, hi = m - 1;

        while (lo <= hi) {
            int mid = (hi + lo)>>1;

            int row = 0;
            for (int i = 1; i < n; i++) {
                if (mat[i][mid] > mat[row][mid])
                    row = i;
            }

            //comparing left and right to find peak
            int left  = (mid > 0) ? mat[row][mid - 1] : -1;
            int right = (mid < m - 1) ? mat[row][mid + 1] : -1;

            if (mat[row][mid] > left && mat[row][mid] > right)
                return {row, mid};

            if (left > mat[row][mid])
                hi = mid - 1;
            else
                lo = mid + 1;
        }

        return {-1, -1};
    }
};