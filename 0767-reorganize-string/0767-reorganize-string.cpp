class Solution {
public:
    string reorganizeString(string s) {
        vector<int> mp(26, 0);
        for(char c : s){
            mp[c - 'a']++;
        }
        priority_queue <pair<int, char>> pq;

        for(int i=0; i<26; i++){
            if(mp[i]) pq.push({mp[i], 'a' + i});
        }

        string ans = "";
        int size = 0;
        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();
            if(size == 0 || ans[size - 1] != p.second){
                ans.push_back(p.second);
                p.first--;
            }
            else{
                if(pq.empty()) return ""; //not possible as no other letter exists to come in b/w
                auto n = pq.top();
                pq.pop();
                ans.push_back(n.second);
                n.first--;
                if(n.first) pq.push(n);
            }

            size++;
            if(p.first) pq.push(p);
        }

        return ans;
    }
};