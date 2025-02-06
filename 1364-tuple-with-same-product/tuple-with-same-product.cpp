class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        map<int,int> m;
        int count=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                int pro=nums[i]*nums[j];
                if(m.find(pro)!=m.end()){
                    count+=m[pro]*8;
                }
                m[pro]++;
            }
        }return count;
    }
};