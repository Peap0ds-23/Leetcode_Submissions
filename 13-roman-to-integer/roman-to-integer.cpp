class Solution {
public:
    int romanToInt(string s) {
        int sum=0;
        unordered_map<string,int> m={{"IV",4},{"IX",9},{"XL",40},{"XC",90},{"CD",400},{"CM",900},{"I",1},{"V",5},{"X",10},{"L",50},{"C",100},{"D",500},{"M",1000}};

        for(int i=0;i<s.size();i++){
            if((i+1)<s.size() && m.find(s.substr(i,2))!=m.end()){
                sum+=m[s.substr(i,2)];
                i++;
            }else{
                sum+=m[s.substr(i,1)];
            }
            // if((i+1)<s.size() && s.substr(i,2)=="IV"){
            //     sum+=4;
            //     i++;
            // }
            // else if((i+1)<s.size() && s.substr(i,2)=="IX"){
            //     sum+=9;
            //     i++;
            // }
            // else if((i+1)<s.size() && s.substr(i,2)=="XL"){
            //     sum+=40;
            //     i++;
            // }
            // else if((i+1)<s.size() && s.substr(i,2)=="XC"){
            //     sum+=90;
            //     i++;
            // }
            // else if((i+1)<s.size() && s.substr(i,2)=="CD"){
            //     sum+=400;
            //     i++;
            // }
            // else if((i+1)<s.size() && s.substr(i,2)=="CM"){
            //     sum+=900;
            //     i++;
            // }
            // else if(s[i]=='I'){
            //     sum+=1;
            // }
            // else if(s[i]=='V'){
            //     sum+=5;
            // }
            // else if(s[i]=='X'){
            //     sum+=10;
            // }
            // else if(s[i]=='L'){
            //     sum+=50;
            // }
            // else if(s[i]=='C'){
            //     sum+=100;
            // }
            // else if(s[i]=='D'){
            //     sum+=500;
            // }
            // else if(s[i]=='M'){
            //     sum+=1000;
            // }
        }return sum;
    }
};