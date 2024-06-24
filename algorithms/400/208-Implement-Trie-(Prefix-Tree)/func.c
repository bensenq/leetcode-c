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

bool trieSearch(Trie* obj, char* word) {
    Trie *node = obj;
    for (int i = 0; word[i]; i++) {
        int index = word[i] - 'a';
        if (!node->childNode[index]) {
            return false; 
        }
        node = node->childNode[index];
    }
    return node->wordEnd;    
}

bool trieStartsWith(Trie* obj, char* prefix) {
    Trie *node = obj;
    for (int i = 0; prefix[i]; i++) {
        int index = prefix[i] - 'a';
        if (!node->childNode[index]) {
            return false; 
        }
        node = node->childNode[index];
    }
    return true;
}

void trieFree(Trie* obj) {
    free(obj);
}

/**
 * Your Trie struct will be instantiated and called as such:
 * Trie* obj = trieCreate();
 * trieInsert(obj, word);
 
 * bool param_2 = trieSearch(obj, word);
 
 * bool param_3 = trieStartsWith(obj, prefix);
 
 * trieFree(obj);
*/