class Solution {
public:
    string intToRoman(int num) {
        int p=log10(num),b,c,a;
        string ans="",st;
        unordered_map<int,string> m;
        m[1]="I";
        m[5]="V";
        m[10]="X";
        m[50]="L";
        m[100]="C";
        m[500]="D";
        m[1000]="M";
        m[4]="IV";
        m[9]="IX";
        m[40]="XL";
        m[90]="XC";
        m[400]="CD";
        m[900]="CM";
        // b=(num%10);

        // num/=10;
        for(int i=0;i<=p;i++){
            b=(num%10);
            c=pow(10,i);
            a=b*c;
            st="";
            // if(b==0){
            //     continue;
            // }
            if(b>0 && b<4){
                while(b>0){
                    st+=m[c];
                    b--;
                }
            }
            else if(b==4){
                st+=m[a];
            }
            else if(b>0 && b<9){
                st+=m[5*c];
                while(b>5){
                    st+=m[c];
                    b--;
                }
            }
            else if(b==9){
                st+=m[a];
            }
            ans=st+ans;
            num/=10;
        }return ans;
    }
};