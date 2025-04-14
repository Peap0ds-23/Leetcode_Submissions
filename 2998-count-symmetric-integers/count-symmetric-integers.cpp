class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count=0;
        for(int i=low;i<=high;i++){
            if((i>=10 && i<=99) || (i>=1000 && i<=9999)){
                int len=(int)log10(i)+1;
                int sum1=0;
                int sum2=0;
                int temp=i;
                for(int j=len/2;j<len;j++){
                    sum2+=temp%10;
                    temp/=10;
                }
                for(int j=0;j<len/2;j++){
                    sum1+=temp%10;
                    temp/=10;
                }
                if(sum1==sum2){
                    count++;
                }

            }
        }return count;
    }
};