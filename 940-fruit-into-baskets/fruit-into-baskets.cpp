class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        if(n<=2){
            return n;
        }
        int i=0,j=0;
        int maxx=0;
        map<int,int> m;
        int count=0;
        while(j<n){
            m[fruits[j]]++;
            count++;
            if(m.size()<=2){
                maxx=max(maxx,count);
                j++;
            }else{
                while(m.size()>2){
                    m[fruits[i]]--;
                    count--;
                    if(m[fruits[i]]==0){
                        m.erase(fruits[i]);
                    }
                    i++;
                }
                maxx=max(maxx,count);
                j++;
            }
        }return maxx;
    }
};