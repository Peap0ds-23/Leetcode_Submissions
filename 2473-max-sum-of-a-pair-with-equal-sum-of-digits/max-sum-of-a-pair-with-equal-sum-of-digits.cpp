class Solution {
public:
    int maximumSum(vector<int>& nums) {
        map<int,int> m;
        int maxx=-1;
        for(int i=0;i<nums.size();i++){
            int temp=nums[i];
            int sumOfDigit=0;
            while(temp>0){
                sumOfDigit+=temp%10;
                temp/=10;
            }
            if(m.find(sumOfDigit)!=m.end()){
                maxx=max(maxx,nums[i]+m[sumOfDigit]);
                m[sumOfDigit]=max(nums[i],m[sumOfDigit]);
            }else{
                m[sumOfDigit]=nums[i];
            }   
        }return maxx;
    }
};