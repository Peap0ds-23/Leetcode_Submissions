class Solution {
    public List<List<Integer>> mergeSimilarItems(int[][] items1, int[][] items2) {
        
        List<List<Integer>> list =new ArrayList<>();
        int[] arr=new int[1002];
        for(int[] nums:items1){
            arr[nums[0]]+=nums[1];
        }
        for(int[] nums:items2){
            arr[nums[0]]+=nums[1];
        }
        for(int i=1;i<1001;i++){
            if(arr[i]>0){
                ArrayList<Integer> temp=new ArrayList<>();
                temp.add(i);
                temp.add(arr[i]);
                list.add(temp);
            }    
        }
        return list;
    }
}
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
//         QS(items1,0,items1.length-1);
//         QS(items2,0,items2.length-1);
        
//         List<List<Integer>> list = new ArrayList<ArrayList<Integer>>(); 
//             int k=0;
//             int i = 0;
//             int j = 0;
//             // int k = 0;
//             while (i < items1.length && j < items2.length) {
//                 if(items1[i][0]==items2[j][0]){
//                     list.get(k).set(0,items1[i][0]);
//                     list.get(k).set(1,items1[i][1]+items2[j][1]);
                    
//                     i++;
//                     j++;
                    
//                 }
//                 else if (items1[i][0] < items2[j][0]) {
//                     list.get(k).set(0,items1[i][0]);
//                     list.get(k).set(0,items1[i][1]);
//                     i++;
                    
//                 } else {
//                     list.get(k).set(0,items2[j][0]);
//                     list.get(k).set(0,items2[j][1]);
//                     j++;
//                 }
//                 k++;
//             }
//              while (i < items1.length) {
//                 list.get(k).set(0,items1[i][0]);
//                 list.get(k).set(0,items1[i][1]);
//                 i++;
//                 k++;
//             }

//             while (j < items2.length) {
//                 list.get(k).set(0,items2[j][0]);
//                 list.get(k).set(0,items2[j][1]);
//                 j++;
//                 k++;
//             }
//         // ArrayList resultsObjects = new ArrayList();
//             // List<List<string>> results = list.Cast<List<string>>();
//             return list;
        
//     }
//     public void QS(int[][] nums, int low, int hi){
//         if (low >= hi) {
//             return;
//         }

//         int s = low;
//         int e = hi;
//         int m = s + (e - s) / 2;
//         int pivot = nums[m][0];

//         while (s <= e) {

//             // also a reason why if its already sorted it will not swap
//             while (nums[s][0] < pivot) {
//                 s++;
//             }
//             while (nums[e][0] > pivot) {
//                 e--;
//             }

//             if (s <= e) {
//                 int temp1 = nums[s][0];
//                 nums[s][0] = nums[e][0];
//                 nums[e][0] = temp1;
//                 int temp2 = nums[s][1];
//                 nums[s][1] = nums[e][1];
//                 nums[e][1] = temp2;
//                 s++;
//                 e--;
//             }
//         }
//     }

// }