class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int n=num2;
        long count1=0,count2=0;
        while(n){
            count2+=n&1;
            n=n>>1;
        }
        n=num1;
        while(n){
            count1+=n&1;
            n=n>>1;
        }
        int mask=0,n1;
        for(int i=31;i>=0;i--){
            if(num1 & (1<<i)){
                mask |=(1<<i);
                n1++;
                if(n1==count2){
                    break;
                }
            }
        }
        if(count1==count2){
            return num1;
        }else if(count1>count2){
            return mask;
        }else{
            int rem=count2-count1;
            int pos=0;
            int count=0;
            while(count<rem){
                if((num1 &(1<<pos))==0){
                    num1 |=(1<<pos);
                    
                    count++;
                }
                pos++;
            }
            return num1;
        }return 0;

    }
};