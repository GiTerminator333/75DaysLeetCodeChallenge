class Solution {
public:
    int minimumPushes(string word) {
        vector<int> mp(26);
        for(int i=0; i<word.length(); i++){
            mp[word[i] - 'a']++;
        }

        priority_queue<int> pq;
        for(int i=0; i<26; i++){
            pq.push(mp[i]);
        }

        int cnt = 0; //count no of buttons assigned (2-9)
        int click = 1;  //click to press each time
        int totClicks = 0;
        while(!pq.empty()){
            if(cnt == 8){
                //all 8 buttons already assigned the curr click amt
                cnt = 0;
                click++;
            }
            int f = pq.top();
            pq.pop();

            totClicks += f * click;
            cnt++;
        }

        return totClicks;
    }
};