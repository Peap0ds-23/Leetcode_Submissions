import java.math.BigInteger;
class Solution {
    public List<Integer> addToArrayForm(int[] num, int k) {
        ArrayList<Integer> list=new ArrayList<>();
        StringBuilder sb2=new StringBuilder();
        
        for(int i:num){
            sb2.append(i);
        }
        String num1=sb2.toString();
        String num2=Integer.toString(k);
        int i=num1.length()-1,j=num2.length()-1,rem=0;
        StringBuilder sb=new StringBuilder();
        while(i>=0 && j>=0){
            int a=(int)(num1.charAt(i)-'0')+ (int)(num2.charAt(j)-'0')+rem;
            sb.append(a%10);
            rem=a/10;
            i--;
            j--;
        }
        while(i>=0){
            int b=(int)(num1.charAt(i)-'0')+rem;
            sb.append(b%10);
            rem=b/10;
            i--;
        }
        while(j>=0){
            int b=(int)(num2.charAt(j)-'0')+rem;
            sb.append(b%10);
            rem=b/10;
            j--;
        }
        if(rem!=0){
            sb.append(rem);
        }
        sb.reverse();
        for(int p=0;p<sb.length();p++){
            list.add((int)(sb.charAt(p)-'0'));
        }return list;

    }
}