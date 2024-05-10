int trap(int* height, int heightSize) {
    int i, j;
    int waters = 0;
    int max_left = 0;
    int max_left_index = 0;
    while(i < heightSize) {
        if(height[i] > 0) {
            if (max_left > 0) {
                int top = 0;
                for(j = i-1; j >= max_left_index; j--) {
                    if (height[j] > top) {
                        if (height[j] < height[i]) {
                            waters += (i - j - 1) * (height[j] - top);
                            top = height[j];
                        } else {
                            waters += (i - j - 1) * (height[i] - top);
                            break;
                        }
                    }
                }
            }
            if (height[i] >= max_left) {
                max_left = height[i];
                max_left_index = i;
            }
        }
        i++;
    }
    
    return waters;
}

int main()
{
    int data[12] = {0,1,0,2,1,0,1,3,2,1,2,1};
    return trap(data, 12);
}