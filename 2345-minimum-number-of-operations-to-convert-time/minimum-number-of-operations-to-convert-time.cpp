class Solution {
public:
    int convertTime(string current, string correct) {
        int currHour=current[0]-'0';
        currHour*=10;
        currHour+=current[1]-'0';
        
        int currMin=current[3]-'0';
        currMin*=10;
        currMin+=current[4]-'0';

        int targetHour=correct[0]-'0';
        targetHour*=10;
        targetHour+=correct[1]-'0';

        int targetMin=correct[3]-'0';
        targetMin*=10;
        targetMin+=correct[4]-'0';
        cout<<currHour<<" "<<currMin<<" "<<targetHour<<" "<<targetMin;
        int count=0;
        count+=(targetHour-currHour);
        if(targetMin==currMin){
            return count;
        }else if(targetMin>currMin){
            int diff=targetMin-currMin;
            count+=diff/15;
            diff%=15;
            count+=diff/5;
            diff%=5;
            count+=diff;
            return count;
        }else{
            int diff=targetMin-currMin;
            diff+=60;
            count--;
            count+=diff/15;
            diff%=15;
            count+=diff/5;
            diff%=5;
            count+=diff;
            return count;
        }


        return 0;
        
    }
};