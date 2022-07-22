class Solution {
    public int arrangeCoins(int n) {
        // solution 1 using mathematical approach
    long a=n;
        int ans=(int)(Math.sqrt(2*a+0.25)-0.5);
        return ans;
    }
    
}