class Solution {
    public boolean checkIfExist(int[] arr) {
        // first sort the array
        Arrays.sort(arr);
        for(int i=0;i<arr.length-1;i++){
            int target=2*arr[i];
            int st=0;
            int en=arr.length-1;
            while(st<=en){
                int mid=st+(en-st)/2;
                if(arr[mid]==target && i!=mid){
                    return true;
                }
                else if(arr[mid]>target){
                    en=mid-1;
                }
                else{
                    st=mid+1;
                    
                }
            }
        }return false;
    }
}