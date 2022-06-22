class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int p=digits.size();
        if(digits[p-1]!=9){
            digits[p-1]++;
            return digits;
        }
        int a=0;
        for(int i=0;i<p;i++){
            if(digits[p-1-i]==9){
                a++;
            }
        }
        if(a==p){
            // int arr[p+1];
            // arr[0]=1;
            vector<int> arr;
            arr.push_back(1);
            for(int i=1;i<p+1;i++){
                arr.push_back(0);
            }
            return arr;
        }
        int carry=1;
        for(int i=p-1;i>=0;i--){
            digits[i]+=carry;
            if(digits[i]>9){
                carry=digits[i]/10;
                digits[i]=digits[i]%10;
            }else{
                carry=0;
            }
        }return digits;
    }
};