/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
       
        int low,high;
        low = 1;
        high = n;
        
        while(low<=high){
            int mid = low + (high-low)/2;
            int cur_ans = guess(mid);
            if(cur_ans==0){
                return mid;
            } else if(cur_ans==-1){
                high = mid-1;
            } else if(cur_ans == 1){
                low = mid+1;
            }
        }

        return -1;
    }
};