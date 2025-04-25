class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int count=0;
        int i=1,j=1;
        while(i<nums.size()){
            int minn=INT_MAX,ind=-1;
            bool flag=false;
            j=1;
            while(j<nums.size()){
                if(nums[j]<nums[j-1]){
                    flag=true;
                }
                int temp=nums[j]+nums[j-1];
                if(temp<minn){
                    minn=temp;
                    ind=j;
                }
                j++;
            }

            if(!flag){
                return count;
            }
            if(ind!=-1){
                nums[ind-1]=minn;
                nums.erase(nums.begin()+ind);
                count++;
            }else{
                i++;
            }
            
            // for(int k=0;k<nums.size();k++){
            //     cout<<nums[k]<<":";
            // }
            // cout<<endl;
        }
        return count;
    }
};