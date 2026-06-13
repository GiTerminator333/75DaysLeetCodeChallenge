class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        //codestorywithMIK
        vector<int> mp(26, 0);
        for(char ch : tasks){
            mp[ch - 'A']++;
        }
        priority_queue<int> pq;

        for(int i=0; i<26; i++){
            if(mp[i]) pq.push(mp[i]);
        }

        int time = 0;
        while(!pq.empty()){
            vector<int> temp;
            for(int i=0; i<n+1; i++){
                if(pq.empty()) break;
                int freq = pq.top();
                pq.pop();
                freq--;
                temp.push_back(freq);
            }

            for(int i=0; i<temp.size(); i++){
                if(temp[i]) pq.push(temp[i]);
            }

            if(pq.empty()){
                time += temp.size();
            }
            else{
                time += n+1;
            }
        }

        return time;
    }
};