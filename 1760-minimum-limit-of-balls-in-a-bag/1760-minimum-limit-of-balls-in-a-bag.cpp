class Solution {
public:
    bool isPenalty(vector<int> &nums, int maxPenal, int maxOp){
        //mujhe max no of balls penal karni h
        int opCount = 0;
        for(int &x : nums){
            if(x > maxPenal){
                opCount += (x % maxPenal)? x/maxPenal : x/maxPenal - 1;
                if(opCount > maxOp) return false;
            }
        }

        return opCount <= maxOp;
    }

    int minimumSize(vector<int>& nums, int maxOperations) {
        //the more u dvide the bag the less it the size of max size bag ie penalty bag
        // more operation  -> more bag -> less size -> less penalty

        int lo = 1, hi = *max_element(nums.begin(), nums.end());

        while(lo <= hi){
            int mid = (lo + hi)>>1;

            if(isPenalty(nums, mid, maxOperations)){
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }

        return lo;
    }
};