class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        if(n2 < n1) return findMedianSortedArrays(nums2, nums1); //applying binary search on shorter array for optimization

        int lo = 0, hi = n1;
        int left = (n1 + n2 + 1)/ 2; //tot no of ele on the left half
        int n = n1 + n2;
        while(lo <= hi){
            int mid1 = (lo + hi)>>1;
            int mid2 = left - mid1; 
            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;
            //taking l1 = INT_MIN and r1 = INT_MAX to manage out of bound cases of mid1 = 0 && mid1 = 6

            if(mid1 < n1) r1 = nums1[mid1];
            if(mid2 < n2) r2 = nums2[mid2];

            if(mid1 > 0) l1 = nums1[mid1 - 1];
            if(mid2 > 0) l2 = nums2[mid2 - 1];

            if(l1 <= r2 && l2 <= r1){
                if(n%2){
                    //n1 + n2 = odd no of ele in array -> single median
                    return max(l1, l2);
                }
                else return (double)(max(l1, l2) + min(r1, r2)) / 2.0;
            }

            else if(l1 > r2){
                //l1 ko right behjo
                hi = mid1 - 1;
            }
            else lo = mid1 + 1;
        } 

        return -1;
    }
};