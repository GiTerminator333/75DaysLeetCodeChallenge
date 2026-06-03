class Solution {
public:
    int findMinTime(vector<int>& start1, vector<int>& dur1, vector<int>& start2, vector<int>& dur2){
        //finding min possible finish time for ride 1
        int finish1 = INT_MAX;
        for(int i=0; i<start1.size(); i++){
            finish1 = min(finish1, start1[i] + dur1[i]);
        }

        int finish2 = INT_MAX;
        for(int i=0; i<start2.size(); i++){
            finish2 = min(finish2, max(finish1, start2[i]) + dur2[i]);
            //if ride finish brfore other ride starts, wait (addd start time of ride 2)
            // else immidiately ride after finish1
        }

        return finish2;
    }
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        return min(findMinTime(landStartTime, landDuration,waterStartTime,waterDuration),
                    findMinTime(waterStartTime, waterDuration,landStartTime, landDuration));
    }
};