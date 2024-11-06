#include <stdio.h>

int hashTable[10] = {0}; // Initialize all elements to 0

int hashFunction(int key) {
    return key % 10;
}

void insertKey(int key) {
    int index = hashFunction(key);
    hashTable[index] = key;
}

int searchKey(int key) {
    int index = hashFunction(key);
    if (hashTable[index] == key) {
        return index;
    } else {
        return -1;
    }
}

int main() {
    int n, key, index;

    // Insert keys into the hash table
    printf("Enter the number of keys to insert: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter key %d: ", i + 1);
        scanf("%d", &key);
        insertKey(key);
    }

    // Search for a key in the hash table
    printf("Enter a key to search for: ");
    scanf("%d", &key);
    index = searchKey(key);

    if (index != -1) {
        printf("Key %d found at index %d\n", key, index);
    } else {
        printf("Key %d not found\n", key);
    }

    return 0;
}
