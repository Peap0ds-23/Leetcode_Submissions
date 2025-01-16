class Solution {
public:
    int LCM(int a,int b){
        int maxx;
        maxx=a>b?a:b;
        for(int i=maxx;i<=a*b;i++){
            if(i%a==0 && i%b==0){
                return i;
            }
        }
        return a*b;
    }
    int HCF(int a,int b){
        int minn;
        minn=(a>b)?b:a;
        for(int i=minn;i>0;i--){
            if(a%i==0 && b%i==0){
                return i;
            }
        }
        return 1;
    }
    int maxLength(vector<int>& nums) {
        int n=nums.size();
        int maxx=0;
        for(int i=0;i<n;i++){
            int lcm=nums[i];
            int hcf=nums[i];
            int pro=nums[i];
            
            for(int j=i+1;j<n;j++){
                lcm=LCM(lcm,nums[j]);
                hcf=HCF(hcf,nums[j]);
                if((pro)>INT_MAX/nums[j]){
                    break;
                }
                pro*=nums[j];
                if(pro==lcm*hcf){
                    maxx=max(maxx,j-i+1);
                }
            }
        }return maxx;
    }
};