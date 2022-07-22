/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

public class Solution extends GuessGame {
    public int guessNumber(int n) {
        int st=1,en=n;
        while(st<=en){
            int mid=st+(en-st)/2;
            int neww=guess(mid);
            if(neww==0){
                return mid;
            }
            else if(neww==1){
                st=mid+1;
            }
            else{
                en=mid-1;
            }
        }return -1;
        
    }
}