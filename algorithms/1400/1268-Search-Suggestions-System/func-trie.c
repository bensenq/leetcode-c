/* trie + dfs traverse*/

typedef struct TrieNode {
    struct TrieNode *childNode[26];
    bool wordEnd;    
} Trie;


Trie* trieCreate() {
    Trie *node = (Trie *)malloc(sizeof(Trie));
    memset(node->childNode, 0, sizeof(node->childNode));
    node->wordEnd = false;
    return node;
}

void trieInsert(Trie* obj, char* word) {
    Trie *node = obj;
    for (int i = 0; word[i]; i++) {
        int index = word[i] - 'a';
        if (!node->childNode[index]) {
            node->childNode[index] = trieCreate();
        }
        node = node->childNode[index];
    }
    node->wordEnd = true;    
}

void trieTraverse(Trie *obj, char* data, int len, int i, char ***result, int *returnSize) {
    Trie *node = obj;
    if (node->wordEnd) {
        // printf("%d, %d, %d\n", i, returnSize[i], len);
        result[i][returnSize[i]] = strndup(data, len);
        returnSize[i]++;
        if (returnSize[i] == 3) return;
    }
    for (int k = 0; k < 26; k++) {
        if (node->childNode[k]) {
            data[len] = 'a' + k;
            trieTraverse(node->childNode[k], data, len+1, i, result, returnSize);
            if (returnSize[i] == 3) break;
        }
    }
}

void trieSuggest(Trie* obj, char* word, char ***result, int *returnSize) {
    Trie *node = obj;
    char data[3001];
    int i;
    for (i = 0; word[i]; i++) {
        returnSize[i] = 0;
        int index = word[i] - 'a';
        if (node->childNode[index] == 0) {
            break;
        }
        data[i] = word[i];
        result[i] = malloc(sizeof(char *) * 3);
        trieTraverse(node->childNode[index], data, i+1, i, result, returnSize);
        result[i] = realloc(result[i], sizeof(char *) * returnSize[i]);
        node = node->childNode[index];
    }
    for (; word[i]; i++) returnSize[i] = 0;
}

void trieFree(Trie* obj) {
    Trie *node = obj;
    for (int i = 0; i < 26; i++) {
        if (node->childNode[i])
            trieFree(node->childNode[i]);
    }
    free(node);
}

/**
 * Your Trie struct will be instantiated and called as such:
 * Trie* obj = trieCreate();
 * trieInsert(obj, word);
 
 * bool param_2 = trieSearch(obj, word);
 
 * bool param_3 = trieStartsWith(obj, prefix);
 
 * trieFree(obj);
*/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char*** suggestedProducts(char** products, int productsSize, char* searchWord, int* returnSize, int** returnColumnSizes) {
    int n = strlen(searchWord);
    char ***result = calloc(sizeof(char **), n);    //initial to NULL
    *returnColumnSizes = malloc(sizeof(int) * n);
    Trie* root = trieCreate();
    for (int i = 0; i < productsSize; i++) {
        trieInsert(root, products[i]);
    }
    trieSuggest(root, searchWord, result, *returnColumnSizes);
    trieFree(root);
    *returnSize = n;
    return result;
}