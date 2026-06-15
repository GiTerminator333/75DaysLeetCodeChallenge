class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        //check notes(LC)
        int n = arr.size();
        int lo = 0, hi = n - 1;


        while(lo <= hi){
            int mid = (lo + hi)/2;
            //finding no of missing ele present uptil idx i
            int missing = arr[mid] - (mid + 1); //ideally (i+1) should be at idx i

            if(missing < k){
                lo = mid + 1;
            }

            else hi = mid - 1;
            //5th missing number...reach the point where missing > 5
        }
        
        return hi + k + 1;
        //after the BS...high at point where missing <= k, lo at point where missing > k
        //missing = arr[hi] - (hi + 1)
        // more ele to reach kth val = k - missing

        //val = arr[hi] + more = arr[hi] + (k - missing)
        //subsituting val of missing we get
        //val = hi + k + 1
    }
};