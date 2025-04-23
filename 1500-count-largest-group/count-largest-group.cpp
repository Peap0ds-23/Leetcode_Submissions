class Solution {
public:
    int countLargestGroup(int n) {

        vector<int> temp(37,0);
        int ans=0;
        int maxx=0;
        for(int i=1;i<=n;i++){
            int sum=0;
            int rem=i;
            while(rem){
                sum+=rem%10;
                rem/=10;
            }
            temp[sum]++;
            maxx=max(maxx,temp[sum]);
            
            // if(temp[sum]==maxx){
            //     ans++;
            // }else if(temp[sum])
            // maxx=max(maxx,)
        }
        for(int i=0;i<37;i++){
            if(temp[i]==maxx){
                ans++;
            }
        }return ans;
    }
};