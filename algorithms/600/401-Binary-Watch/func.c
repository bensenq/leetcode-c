void genTime(int turnedOn, int *bitmap, int start, char **result, int *size) {    
    if(turnedOn == 0) {
        char minute = (*bitmap) & 0x3f;
        if (minute > 59)    /* not valid minute */
            return;
        char hour = (*bitmap) >> 6;
        char *tmp = calloc(6,1);
        sprintf(tmp, "%d:%02d", hour, minute);
        result[*size] = tmp;
        (*size)++;
        return;
    }
    
    for (int i = start; i <= 10 - turnedOn; i++) {
        if (i == 1 && ((*bitmap) & 1 << 9))   /* skip invalid hour (8+4>11) */
            continue;  
        *bitmap |= 1 << (9 - i);    //set
        genTime(turnedOn-1, bitmap, i+1, result, size);
        *bitmap &= ~(1 << (9 - i)); //clear
    }
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** readBinaryWatch(int turnedOn, int* returnSize){
    int turnonBitmap = 0;
    char ** result = malloc(12*60*sizeof(char *));
    *returnSize = 0;
    genTime(turnedOn, &turnonBitmap, 0, result, returnSize);
    return result;
}