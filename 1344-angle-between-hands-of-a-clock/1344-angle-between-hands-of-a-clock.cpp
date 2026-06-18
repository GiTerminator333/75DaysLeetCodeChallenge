class Solution {
public:
    double angleClock(int hour, int minutes) {
        //360/60 = 6 deg for each min
        //1 ---- 2 => 5 * 6 = 30 degrees
        //hour hand moves as min hand moves
        //12 passes of min =  1 pass of hour
        //x min = x/12 hr
        //deg(x min) = x/12 * 6 = x/2 <== angle of hr hand to move for x min
        
        //calculating clockwise angle of min 
        double minAngle = minutes * 6.0;
        //hour hand angle
        double hrAngle = hour * 30.0 + (minutes/2.0); 
        
        //calc smaller angle -> assign quadrants
        double diff = abs(minAngle - hrAngle);

        if(diff >= 0 && diff <= 180.0){
            return diff;
        }
        
        return 360.0 - diff;
    }
};