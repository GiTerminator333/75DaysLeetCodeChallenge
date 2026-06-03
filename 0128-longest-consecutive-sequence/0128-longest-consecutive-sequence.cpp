class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //bruteforce O(n^2) -> better O(nlogn + n)
        //idea is to find the last smaller element of the sequence

        // sort(nums.begin(), nums.end());

        // int maxi = INT_MIN;
        // int lastSmallest = INT_MIN;
        // int count = 1;

        // for(int i=0; i<nums.size(); i++){
        //     if(lastSmallest == nums[i] - 1){
        //         //mere se pehle wala exist karta hai
        //         count++;
        //         lastSmallest = nums[i];
        //     }
        //     else if(lastSmallest != nums[i]){
        //         //repeating no. nhi hai
        //         //last smallest consecutive bhi nhi hai (condt 1)
        //         //nya seq start hoga
        //         count = 1;
        //         lastSmallest = nums[i];
        //     }

        //     maxi = max(count, maxi);
        // }

        // return maxi;
        
        //Optimal O(n)
        //idea is to find the starting of the seq and then finding greater ele
        int n = nums.size();
        if(n == 0) return 0;

        unordered_set<int> st;
        for(int i=0; i<n; i++) st.insert(nums[i]);

        int maxi = INT_MIN;
        for(int it : st){
            if(st.find(it - 1) == st.end()){
                //no smaller ele of the seq exists
                int count = 1;
                int x = it;

                while(st.find(x+1) != st.end()){
                    count++;
                    x++;
                }

                maxi = max(maxi, count);
            }
        }

        return maxi;
    }
};