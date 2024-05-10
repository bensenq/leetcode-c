char** findWords(char** words, int wordsSize, int* returnSize) {
        int i, j, n = 0;
        char mapping[] = {
        /*      A, B, C, D, E, F, G, H, I, G, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z */
                2, 3, 3, 2, 1, 2, 2, 2, 1, 2, 2, 2, 3, 3, 1, 1, 1, 1, 2, 1, 1, 3, 1, 3, 1, 3,
                0, 0, 0, 0, 0, 0,
        /*      a, b, c, d, e, f, g, h, i, g, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z */
                2, 3, 3, 2, 1, 2, 2, 2, 1, 2, 2, 2, 3, 3, 1, 1, 1, 1, 2, 1, 1, 3, 1, 3, 1, 3,
        };
        char ** ret = malloc (wordsSize * sizeof(char *));
        for (i = 0; i < wordsSize; i++) {
                int row = mapping[words[i][0] - 'A'];
                int inonerow = 1;
                j = 1;
                while (words[i][j] != 0) {
                        if (mapping[words[i][j] - 'A'] != row) {
                                inonerow = 0;
                                break;
                        }
                        j++;
                }
                if (inonerow == 1) {
                        ret[n] = words[i];
                        n++;
                }
        }
        *returnSize = n;
        return ret;
}
