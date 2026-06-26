struct cmp{
    bool operator()(const auto &a, const auto &b){
        if(a.first != b.first) return a.first > b.first;
        return a.second < b.second;
    }
};
class Solution {
public:
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        unordered_set<string> good(positive_feedback.begin(), positive_feedback.end());
        unordered_set<string> bad(negative_feedback.begin(), negative_feedback.end());

        typedef pair<int, int> pi;
        priority_queue<pi, vector<pi>, cmp> pq;

        for(int i=0; i<report.size(); i++){
            int score = 0;
            stringstream ss(report[i]);
            string word;
            int sign = 1;
            while(ss >> word){
                if(good.find(word) != good.end()) score += 3;
                if(bad.find(word) != bad.end()) score -= 1;
            }

            if(pq.size() > k && score < pq.top().first) continue;
            pq.push({score, student_id[i]});
            if(pq.size() > k) pq.pop();
        }

        vector<int> ans;
        while(!pq.empty()){
            ans.insert(ans.begin(), pq.top().second);
            pq.pop();
        }

        return ans;
    }
};