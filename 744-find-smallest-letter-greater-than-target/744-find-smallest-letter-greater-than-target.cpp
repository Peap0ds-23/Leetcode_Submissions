class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int st=0,en=letters.size()-1;
        int mid;
        while(st<=en){
            mid=st+(en-st)/2;
            // if(letters[mid]==target){
            //     st=mid+1;
            //     break;
            // }
            if(letters[mid]>target){
                en=mid-1;
            }
            else{
                // if()
                st=mid+1;
            }
        }
        return letters[st%(letters.size())];
    }
};