class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        if(digits[n-1]<9){
            digits[n-1]+=1;
        }else{
            int i=n-1,rem=0;
            while(i>=0 && digits[i]==9){
                digits[i]=0;
                rem=1;
                i--;
            }
            if(i>=0 && rem==1){
                digits[i]+=rem;
            }else{
                digits.push_back(1);
                for(int i=n-1;i>=0;i--){
                    int temp=digits[i+1];
                    digits[i+1]=digits[i];
                    digits[i]=temp;
                }
            }
        }
        return digits;
    }
};