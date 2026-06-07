class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int i=0; i<asteroids.size(); i++){
            if(asteroids[i] > 0 || st.empty()) st.push(asteroids[i]);
            else if(st.top() < 0){
                st.push(asteroids[i]);
            }
            else{
                int val = abs(asteroids[i]);
                while(!st.empty() && st.top() > 0 && val > st.top()) st.pop();
                if(!st.empty() && st.top() >= val){
                    if(st.top() == val) st.pop();
                    continue;
                }
                else st.push(asteroids[i]);
            }
        }

        vector<int> v;
        while(!st.empty()){
            v.insert(v.begin(), st.top());
            st.pop();
        }

        return v;
    }
};