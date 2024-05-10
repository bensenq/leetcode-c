bool checkStraightLine(int** coordinates, int coordinatesSize, int* coordinatesColSize){
    bool ret;
    if (coordinates[1][1] != coordinates[0][1]) {
        int i = 2;
        float slope = ((float)(coordinates[1][0] - coordinates[0][0])) / 
                            (coordinates[1][1] - coordinates[0][1]);
        int lastx = coordinates[1][0], lasty = coordinates[1][1];
        while (i < coordinatesSize) {
            float s = ((float)(coordinates[i][0] - lastx)) / 
                        (coordinates[i][1] - lasty);
            if (s != slope) { ret = false; goto out; }
            i++;
        }
        ret = true;
        goto out;
    } else {
        int i = 2;
        int lasty = coordinates[1][1];
        while (i < coordinatesSize) {
            if (coordinates[i][1] != lasty) { ret = false; goto out; }
            i++;
        }
        ret = true;
        goto out;
    }
out:
    return ret;
}