class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        // in nlogn
        Arrays.sort(nums1);
        Arrays.sort(nums2);
        ArrayList<Integer> list=new ArrayList<Integer>();
        for(int i=0;i<=1000;i++){
            if(BS(nums1,i)==true && BS(nums2,i)==true){
                list.add(i);
            }
            
        }
        int[] ints = new int[list.size()];
        for (int i = 0; i < list.size(); i++) {
            ints[i]=list.get(i);
        }
        return ints;
    }
    
    boolean BS(int[] arr,int i){
        int st=0,en=arr.length-1;
        while(st<=en){
            int mid=st+(en-st)/2;
            if(arr[mid]==i){
                return true;
            }
            else if(arr[mid]>i){
                en=mid-1;
            }
            else{
                st=mid+1;
            }
        }return false;
    }
}