class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int st=0,en=letters.size()-1,mid;
        while(st<=en){
            mid=st+(en-st)/2;
            if(letters[mid]>target){
                en=mid-1;
            }
            else{
                st=mid+1;
            }
        }return letters[st%letters.size()];
    }
};