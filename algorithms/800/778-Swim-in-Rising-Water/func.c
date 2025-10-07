#include <stdlib.h>
#include <string.h>
// min heap
typedef struct { int h, x, y; } Node;
typedef struct { Node *d; int sz, cap; } MinHeap;

static void swap(Node *a, Node *b) { Node t = *a; *a = *b; *b = t; }
static void push(MinHeap *h, int hh, int xx, int yy) {
    int i = ++h->sz;
    if (h->sz == h->cap) { h->cap <<= 1; h->d = realloc(h->d, h->cap * sizeof(Node)); }
    h->d[i] = (Node){hh, xx, yy};
    while (i > 1 && h->d[i].h < h->d[i >> 1].h) { swap(&h->d[i], &h->d[i >> 1]); i >>= 1; }
}
static Node pop(MinHeap *h) {
    Node r = h->d[1];
    h->d[1] = h->d[h->sz--];
    int i = 1;
    for (;;) {
        int l = i << 1, r = l | 1, m = i;
        if (l <= h->sz && h->d[l].h < h->d[m].h) m = l;
        if (r <= h->sz && h->d[r].h < h->d[m].h) m = r;
        if (m == i) break;
        swap(&h->d[i], &h->d[m]); i = m;
    }
    return r;
}

int swimInWater(int **grid, int gridSize, int *gridColSize) {
    int N = gridSize;
    char *seen = calloc(N * N, 1);
    MinHeap h = { .d = malloc(256 * sizeof(Node)), .sz = 0, .cap = 256 };
    const int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
    push(&h, grid[0][0], 0, 0);
    seen[0] = 1;
    int ans = 0;
    while (h.sz) {
        Node c = pop(&h);
        int hh = c.h, x = c.x, y = c.y;
        ans = ans > hh ? ans : hh;
        if (x == N - 1 && y == N - 1) { free(seen); free(h.d); return ans; }
        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            int idx = nx * N + ny;
            if (seen[idx]) continue;
            seen[idx] = 1;
            push(&h, grid[nx][ny], nx, ny);
        }
    }
    free(seen); free(h.d); return -1;
}
