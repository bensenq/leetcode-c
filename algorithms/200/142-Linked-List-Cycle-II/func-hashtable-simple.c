/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdio.h>
#include <stdlib.h>

// 定义哈希表项结构
typedef struct HashTableItem {
    struct ListNode *key;
    struct HashTableItem *next; // 用于处理哈希冲突
} HashTableItem;

// 创建新的哈希表项
HashTableItem* createHashTableItem(struct ListNode *key) {
    HashTableItem* item = (HashTableItem*) malloc(sizeof(HashTableItem));
    item->key = key;
    item->next = NULL;
    return item;
}

// 哈希函数
unsigned int hashFunction(struct ListNode *key, unsigned int tableSize) {
    return (unsigned)((long)key % tableSize);
}

// 插入或查找哈希表中的元素
struct ListNode* findOrInsert(HashTableItem **table, unsigned int tableSize, struct ListNode *key) {
    unsigned int hashIndex = hashFunction(key, tableSize);

    HashTableItem* entry = table[hashIndex];
    while (entry != NULL && entry->key != key) {
        entry = entry->next;
    }

    if (entry == NULL) { // 如果未找到，插入新条目
        HashTableItem* newItem = createHashTableItem(key);
        newItem->next = table[hashIndex]; // 处理哈希冲突
        table[hashIndex] = newItem;
        return NULL; // 返回NULL表示这是一个新添加的节点
    } else {
        return entry->key; // 返回已存在的节点地址
    }
}

// 检测循环起始节点的函数
struct ListNode *detectCycle(struct ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return NULL;
    }

    // 使用一个较大的质数作为哈希表大小
    unsigned int tableSize = 9973; // 更大的质数
    HashTableItem** table = (HashTableItem**)calloc(tableSize, sizeof(HashTableItem*));

    struct ListNode* current = head;
    while (current != NULL) {
        struct ListNode* cycleNode = findOrInsert(table, tableSize, current);
        if (cycleNode != NULL) { // 找到了循环
            for(int i = 0; i < tableSize; ++i) { // 释放哈希表占用的内存
                HashTableItem* entry = table[i];
                while(entry != NULL) {
                    HashTableItem* temp = entry;
                    entry = entry->next;
                    free(temp);
                }
            }
            free(table); // 释放哈希表指针数组
            return cycleNode;
        }
        current = current->next;
    }

    for(int i = 0; i < tableSize; ++i) { // 释放哈希表占用的内存
        HashTableItem* entry = table[i];
        while(entry != NULL) {
            HashTableItem* temp = entry;
            entry = entry->next;
            free(temp);
        }
    }
    free(table); // 释放哈希表指针数组
    return NULL;
}