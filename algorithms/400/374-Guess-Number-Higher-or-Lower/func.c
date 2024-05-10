/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

int guessNumber(int n){
	int start = 1, end = n, mid, flag;
    while(start <= end) {
        mid = ((long long)start + end) / 2;
        flag = guess(mid);
        if (flag > 0) {
            start = mid + 1;
        } else if (flag < 0) {
            end = mid - 1;
        } else {
            break;
        }
    }
    return mid;
}