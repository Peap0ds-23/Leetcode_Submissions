class Solution {
    public int[] fairCandySwap(int[] aliceSizes, int[] bobSizes) {
        int sum1=0,sum2=0;
        int[] ans=new int[2];
        ans[0]=-1;
        ans[1]=-1;
        for(int i=0;i<aliceSizes.length;i++){
            sum1+=aliceSizes[i];
        }
        for(int i=0;i<bobSizes.length;i++){
            sum2+=bobSizes[i];
        }
        int diff=(sum2-sum1)/2;
        Arrays.sort(bobSizes);
        for(int i:aliceSizes){
            int target=i+diff;
            int st=0,en=bobSizes.length-1;
            while(st<=en){
                int mid=st+(en-st)/2;
                if(bobSizes[mid]==target){
                    ans[0]=i;
                    ans[1]=target;
                    return ans;
                }
                else if(bobSizes[mid]>target){
                    en=mid-1;
                }
                else {
                    st=mid+1;
                }
            }
        }return ans;
        
    }
}