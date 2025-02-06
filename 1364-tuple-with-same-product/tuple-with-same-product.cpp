class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int count=0;
        for(int i=0;i<n-3;i++){
            for(int j=n-1;j>i+2;j--){
                int st=i+1;
                int en=j-1;
                int mid;
                while(st<en){
                    mid=st+(en-st)/2;
                    int sum1=nums[i]*nums[j];
                    int sum2=nums[en]*nums[st];
                    if(sum1==sum2){
                        count+=8;
                        st++;
                        en--;
                    }else if(sum1>sum2){
                        st++;
                    }else{
                        en--;
                    }

                }
            }
        }return count;
    }
};