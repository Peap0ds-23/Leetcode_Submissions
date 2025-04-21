class Solution {
public:
    string fun(int n,string str){
        if(n==0){
            return str;
        }
        int len=str.size();
        int i=0,j=0,count;
        string temp="";
        while(i<len){
            count=0;
            while(i<len && str[i]==str[j]){
                i++;
                count++;
            }
            temp=temp+to_string(count);
            temp=temp+str[j];
            j=i;
        }
        return fun(n-1,temp);
    }
    string countAndSay(int n) {
        string str="1";
        return fun(n-1,str);
    }
};