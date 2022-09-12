class Solution {
    public int addDigits(int num) {
        int sum;
        
        do{
            sum=0;
            while(num>0){
                sum+=num%10;
                num=num/10;
            }
            num=sum;
            
        }while(sum/10 !=0);
        return sum;
    }
}