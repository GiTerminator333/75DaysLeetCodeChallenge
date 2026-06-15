class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mp;
        for(char c : t) mp[c]++;

        int l = 0, r = 0;
        int mini = INT_MAX;
        int start = -1, end = -1;

        // pre-inserted char of t -> always +ve value from the start
        //we will track count of the +ve va; before decrement
        //if count == t.length -> one sequence is found
        //instead of checking everytime that map val = 0, count will help us 
        int count = 0;
        while(r < s.length()){
            //expand
            if(mp[s[r]] > 0) count++;
            mp[s[r]]--;

            //shrink
            //if map val is ive -> faltu ka word -> remove
            while(mp[s[l]] < 0){
                mp[s[l]]++;
                if(mp[s[l++]] > 0) count--;
            }

            //update
            if(mini > r - l + 1 && count == t.length()){
                start = l;
                end = r;
                mini = r - l + 1;
            }

            r++;
        }
        if(start == -1){
            //no string assigned
            return "";
        }
        return s.substr(start, end - start + 1);
    }
};