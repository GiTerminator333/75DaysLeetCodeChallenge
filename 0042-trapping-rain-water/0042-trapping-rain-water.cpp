class Solution {
public:
    int trap(vector<int>& height) {
        //SPACE OPTIMIZATION SC = O(1) TWO POINTER
        // we only need to know about the max ele of the side that is smaller -> lower bound of water collection
        //explained in notebook

        int l = 0, r = height.size() - 1;
        int leftMax = 0, rightMax = 0;
        int tot = 0;
        while(l < r){
            if(height[l] <= height[r]){
                if(leftMax > height[l]){
                    tot += leftMax - height[l];
                }
                else leftMax = height[l];
                l = l + 1;
            }
            else{
                if(rightMax > height[r]){
                    tot += rightMax - height[r];
                }
                else rightMax = height[r];
                r = r - 1;
            }
        }

        return tot;
    }
};