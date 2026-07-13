class Solution {
public:
    int helper(vector<vector<int>>& students, vector<vector<int>>& mentors, vector<bool> &visited, int idx, int totScore) {
        if(idx == mentors.size()){
            return totScore;
        }

        int maxi = 0;
        for(int i=0; i<visited.size(); i++){
            if(!visited[i]){
                visited[i] = true;
                int score = 0;
                for(int j=0; j<students[i].size(); j++){
                    score += (students[i][j] == mentors[idx][j]);
                }

                maxi = max(maxi , helper(students, mentors, visited, idx + 1, totScore + score));

                visited[i] = false;
            }
        }

        return maxi;
    }
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int m = students.size();
        vector<bool> visited(m, false);
        return helper(students, mentors, visited, 0, 0);
    }
};