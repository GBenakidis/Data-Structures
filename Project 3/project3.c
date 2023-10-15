#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 183719
#define TABLE_SIZE 200003
#define SIZE2 163632

typedef struct WordNode {
    char* word;
    struct WordNode* next;
} WordNode;

typedef struct Item {
    char* str;
    WordNode* chain;
} Item;

WordNode* hashTable[TABLE_SIZE];
int DICT_SIZE = 0;
int temp;

WordNode* insertAtEndAndReturnStart(WordNode* start, const char* x) {
    WordNode* t = (WordNode*)malloc(sizeof(WordNode));
    t->word = strdup(x);
    t->next = NULL;
    if (start == NULL) {
        start = t;
    } else {
        WordNode* temp = start;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = t;
    }
    return start;
}

int isPrime(int a) {
    if (a < 2) return 0;
    for (int i = 2; i * i <= a; i++) {
        if (a % i == 0) {
            return 0;
        }
    }
    return 1;
}

void bigFreeArr(Item* arr) {
    for (int i = 0; i < temp; i++) {
        if (arr[i].str != NULL) {
            free(arr[i].str);
            freeList(arr[i].chain);
        }
    }
    free(arr);
}

void freeList(WordNode* head) {
    while (head != NULL) {
        WordNode* tmp = head;
        head = head->next;
        free(tmp->word);
        free(tmp);
    }
}

void freeArr(char** arr) {
    for (int i = 0; i < temp; i++) {
        if (arr[i] != NULL) {
            free(arr[i]);
        }
    }
    free(arr);
}

unsigned int calculateStringHash(const char* str) {
    unsigned int hash = 0;
    const unsigned int multiplier = 31;  // A prime number that helps avoid collisions
    const unsigned int moduloValue = temp; // Assuming 'temp' is a defined constant
    while (*str) { hash = (*str++) + (multiplier * hash); }
    return hash % moduloValue;
}

void QuickSort(char* a, int l, int r) {
    if (l >= r) return;

    int i = l, j = r + 1;
    int pivot = a[l];

    while (1) {
        do {
            i++;
        } while (i <= r && a[i] < pivot);
        do {
            j--;
        } while (a[j] > pivot);
        if (i >= j) break;
        char temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }

    a[l] = a[j];
    a[j] = pivot;
    QuickSort(a, l, j - 1);
    QuickSort(a, j + 1, r);
}

void secondQuestion() {
    DICT_SIZE = SIZE2;
    temp = SIZE2;

    while (!isPrime(temp)) {
        temp++;
    }

    Item* arr = (Item*)malloc(sizeof(Item) * temp);

    if (arr == NULL) {
        printf("Failed malloc");
        exit(1);
    }

    for (int i = 0; i < temp; i++) {
        arr[i].str = NULL;
        arr[i].chain = NULL;
    }

    FILE* fp = fopen("dictionary.txt", "r");

    if (fp == NULL) {
        printf("Failed to open dictionary.txt\n");
        bigFreeArr(arr);
        exit(1);
    }

    char tmp[30] = { 0 };
    char sorted_tmp[30] = { 0 };

    while (fscanf(fp, "%29s", tmp) == 1) {
        strcpy(sorted_tmp, tmp);
        QuickSort(sorted_tmp, 0, strlen(sorted_tmp) - 1);
        int len = strlen(tmp) + 1;
        int hash = calculateStringHash(sorted_tmp);

        if (arr[hash].str == NULL) {
            arr[hash].str = strdup(sorted_tmp);
        }

        arr[hash].chain = insertAtEndAndReturnStart(arr[hash].chain, tmp);

        for (int i = 0; i < len - 1; i++) {
            tmp[i] = '\0';
            sorted_tmp[i] = '\0';
        }
    }

    fclose(fp);

    printf("Please Give me Word: ");
    scanf("%29s", tmp);
    while (getchar() != '\n');
    int hash = calculateStringHash(tmp);

    if (arr[hash].str != NULL && strcmp(arr[hash].str, tmp) == 0) {
        print_list(arr[hash].chain);
    } else {
        printf("Word not found\n");
    }

    bigFreeArr(arr);
}

unsigned int calculateStringHash(const char* str) {
    unsigned int hash = 0;
    const unsigned int multiplier = 31;
    while (*str) { hash = (*str++) + (multiplier * hash); }
    return hash % TABLE_SIZE;
}

void insertIntoHashTable(const char* word) {
    unsigned int hash = calculateStringHash(word);
    WordNode* newNode = (WordNode*)malloc(sizeof(WordNode));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    newNode->word = strdup(word);
    newNode->next = hashTable[hash];
    hashTable[hash] = newNode;
}

int firstQuestion(void) {
    int DICT_SIZE;
    printf("Give me the Dictionary size (0, 183719): ");
    if (scanf("%d", &DICT_SIZE) != 1 || DICT_SIZE <= 0 || DICT_SIZE > SIZE) {
        printf("Invalid input. Please enter a valid size (0, 183719)\n");
        return 1;
    }

    while (getchar() != '\n'); // Clear the input buffer.

    FILE* fp = fopen("dictionary.txt", "r");
    if (fp == NULL) {
        printf("Failed to open dictionary.txt\n");
        return 1;
    }

    char tmp[30];
    int num = DICT_SIZE;

    while (num > 0 && fscanf(fp, "%29s", tmp) == 1) {
        insertIntoHashTable(tmp);
        num--;
    }

    fclose(fp);

    printf("Please Give me Word: ");
    if (scanf("%29s", tmp) != 1) {
        printf("Invalid input\n");
        return 1;
    }

    while (getchar() != '\n');

    unsigned int hash = calculateStringHash(tmp);
    WordNode* current = hashTable[hash];

    while (current != NULL) {
        if (strcmp(current->word, tmp) == 0) {
            printf("Found: %s\n", tmp);
            break;
        }
        current = current->next;
    }

    if (current == NULL) {
        printf("Word not found\n");
    }

    // Free memory for hash table
    for (int i = 0; i < TABLE_SIZE; i++) {
        WordNode* node = hashTable[i];
        while (node != NULL) {
            WordNode* next = node->next;
            free(node->word);
            free(node);
            node = next;
        }
    }

    return 0;
}

int main(void) {
    firstQuestion();
    secondQuestion();
    return 0;
}