/* two pointer */

void sortColors(int* nums, int numsSize){
    int red = 0, blue = numsSize - 1;
    int t;   
//     int i = red;
//     while(i < numsSize) {
//         if (nums[i] == 0) i++;
//         else {red = i; break;}
//     }
    
//     i = blue;
//     while(i >= 0) {
//         if (nums[i] == 2) i--;
//         else {blue = i; break;}
//     }
    
    int i = red;
    while(i <= blue) {
        if (nums[i] == 0 && i != red) { //red
            t = nums[red];
            nums[red] = 0;
            red++;
            nums[i] = t;
        } else if (nums[i] == 2 && i != blue) {  //blue
            t = nums[blue];
            nums[blue] = 2;
            blue--;
            nums[i] = t;
        } else {    //white
            i++;
        }
    }   
}