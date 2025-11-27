class Solution {
public:
    int reverseBits(int n) {
        int ans=0;
        string s;
        for(int i=0;i<32;i++){
            int curr=n&1;
            if(curr){
                curr=pow(2,32-i-1);
                ans+=curr;
            }
            
            n/=2;
        }
        return ans;
    }
};
// 00000010100101000001111010011100