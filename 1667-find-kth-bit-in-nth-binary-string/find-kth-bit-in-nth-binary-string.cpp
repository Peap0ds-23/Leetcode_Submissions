class Solution {
public:
    char findKthBit(int n, int k) {
        string curr="0";
        while(n>1){
            n--;
            string temp=curr;
            for(int i=0;i<(temp.size()+1)/2;i++){
                int a=temp[i]^1;
                temp[i]=temp[temp.size() -i-1]^1;
                temp[temp.size() -i-1]=a;
            }
            curr+=("1"+temp);
        }
        // cout<<curr;
        return curr[k-1];
    }
};