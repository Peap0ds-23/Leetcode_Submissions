class Solution {
    public String addStrings(String num1, String num2) {
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
        }return sb.reverse().toString();
    }
}