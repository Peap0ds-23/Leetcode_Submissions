class Solution {
public:
    int minimumSum(int num) {
        string s = to_string(num);
        sort(s.begin(),s.end());
        
        int x = (s[0]-'0')*10;
        x += (s[2]-'0');
        
        int y = (s[1]-'0')*10;
        y += (s[3]-'0');
        return x + y;
    }
};