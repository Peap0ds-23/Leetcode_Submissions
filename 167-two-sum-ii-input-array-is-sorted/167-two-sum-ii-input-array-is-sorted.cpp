class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector <int> arr;
        int st=0,en=numbers.size()-1;
        while(st<en){
            if(numbers[st]+numbers[en]==target){
                arr.push_back(st+1);
                arr.push_back(en+1);
                return arr;
            }
            else if(numbers[st]+numbers[en]>target){
                en--;
            }
            else{
                st++;
            }
        }
        return arr;
    }
};