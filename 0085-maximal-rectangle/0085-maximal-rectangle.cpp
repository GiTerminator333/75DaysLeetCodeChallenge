class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> nsi(n, n), psi(n);

        stack <int> st;

        for(int i=0; i<n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                nsi[st.top()] = i;
                st.pop();
            }

            psi[i] = (st.empty())? -1 : st.top();
            
            st.push(i);
        }

        int maxi = 0;
        for(int i=0; i<n; i++){
            maxi = max(maxi, heights[i] * (nsi[i] - psi[i] - 1));
        }


        return maxi;

    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        vector<int> dp(c);
        
        // for(int i=0; i<c; i++){
        //     dp[i] = (matrix[0][i] == '0')? 0 : 1;
        // }


        int maxi = 0;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(matrix[i][j] == '0') dp[j] = 0; //no histogram at curr lvl / reset histogram
                else dp[j]++;

            }
            maxi = max(maxi, largestRectangleArea(dp));
        }

        return maxi;
    }
};