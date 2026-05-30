class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //apply on first co, find floor
        //apply bs on row

        //finding row
        int lo = 0, hi = matrix.size() - 1;
        while(lo <= hi){
            int mid = (lo + hi)/2;
            if(matrix[mid][0] == target) return true;
            if(matrix[mid][0] < target){
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }
        //hi = floor -> row val <= t
        if(hi < 0) return false; //doesnt exists
        int r = hi;
        lo = 0; 
        hi = matrix[0].size() - 1;
        while(lo <= hi){
            int mid = (lo + hi)/2;
            if(matrix[r][mid] == target) return true;
            if(matrix[r][mid] < target){
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }

        return false;
    }
};