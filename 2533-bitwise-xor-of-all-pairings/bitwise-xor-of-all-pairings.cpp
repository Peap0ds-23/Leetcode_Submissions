class Solution {
public:
// a,b,c 1,2,3,4
// a^(1,2,3,4)
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        int xorr=0;
        for(int i=0;i<n;i++){
            xorr^=nums2[i];
        }
        if(n%2==1){
            int temp=0;
            for(int i=0;i<m;i++){
                temp^=(nums1[i]^xorr);
            }
            return temp;
        }else{
            int temp=0;
            if(m%2==0){
                return 0;
            }else{
                return xorr;
                // for(int i=0;i<m;i++){

                // }
            }
        }
        return 0;
        // if(m%2==0 && n%2==0){
        //     return 0;
        // }else if(m%2==0 && n%2==1){

        // }
        
        
    }
};