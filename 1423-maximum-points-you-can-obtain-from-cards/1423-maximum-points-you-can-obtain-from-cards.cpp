class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        //k window max -> n - k window min
        int tot = accumulate(cardPoints.begin(), cardPoints.end(), 0);
        int n = cardPoints.size();
        if(k == n) return tot;

        int l=0, r=0;
        int minSum = INT_MAX;
        int sum = 0;    //subarray sum

        while(r < n){
            sum += cardPoints[r];

            if(r - l + 1 > n - k){
                sum -= cardPoints[l];
                l++;
            }

            if(r - l + 1 == n - k) minSum = min(minSum, sum);
            r++;
        }

        return tot - minSum;
    }
};