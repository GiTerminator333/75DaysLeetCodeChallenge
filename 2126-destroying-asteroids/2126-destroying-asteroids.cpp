class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        int MOD = 1e9 + 7;
        sort(asteroids.begin(), asteroids.end());
        int netMass = mass;
        for(int i=0; i<asteroids.size(); i++){
            if(asteroids[i] > netMass) return false;
            netMass = (netMass%MOD) + (asteroids[i]%MOD);
        }

        return true;
    }
};