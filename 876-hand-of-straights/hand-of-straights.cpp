class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if(n%groupSize !=0){
            return false;
        }
        map<int,int> m;
        for(int i=0;i<n;i++){
            m[hand[i]]++;
        }
        auto it=m.begin();
        while(it!=m.end()){
            int curr=(*it).first;
            int count=(*it).second;
            if(count==0){
                it++;
                continue;

            }
            for(int i=0;i<groupSize;i++){
                if(m[curr+i]<count){
                    return false;
                }
                m[curr+i]-=count;
                // if(m[curr+i]==0){
                //     m.erase(curr+i);
                // }
            }
            it++;
        }
        return true;
    }
};