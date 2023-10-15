#include <stdio.h>
#include <stdlib.h>

#define Max_Num 1000

typedef struct listpointer {
    int x;
    struct listpointer *next;
} list;

typedef struct List {
    int size;
    int elements[Max_Num];
} List;

typedef struct {
    List *ptr_list;
} Item;

int N;
Item *Stack;

int STACKempty() { return N == 0; }

void STACKinit(int maxN) {
    Stack = (Item *)malloc(maxN * sizeof(Item));
    N = 0;
}

void STACKpush(List *item) {
    if (N < Max_Num) {
        Stack[N].ptr_list = item;
        N++;
    } else {
        printf("Stack is full.\n");
        exit(1);
    }
}

Item STACKpop() {
    if (!STACKempty()) {
        N--;
        return Stack[N];
    } else {
        printf("Stack is empty.\n");
        exit(1);
    }
}

void printList(List *lst) {
    for (int i = 0; i < lst->size; i++) {
        if (i > 0) {
            printf("+");
        }
        printf("%d", lst->elements[i]);
    }
    printf("\n");
}

void generateCombinations(int n, List *currentList) {
    if (n == 0) { printList(currentList); return; }
    if (n < 0 || currentList->size >= 2) { return; }

    for (int i = 1; i <= n; i++) {
        currentList->elements[currentList->size] = i;
        currentList->size++;
        STACKpush(currentList);
        generateCombinations(n - i, currentList);
        currentList->size--;
        currentList = STACKpop().ptr_list;
    }
}

void freeStack() {
    for (int i = 0; i < N; i++) { free(Stack[i].ptr_list); }
    free(Stack);
}

int main(void) {
    int choose_number = 0;
    printf("Give an integer positive number between 1 and %d:", Max_Num - 1);
    do {
        scanf("%d", &choose_number);
        if (choose_number <= 0) {
            printf("Please give me a positive integer\n");
        }
        if (choose_number >= Max_Num) {
            printf("Please give a smaller integer\n");
        }
        while (getchar() != '\n');
    } while (choose_number <= 0 || choose_number >= Max_Num);
    Item head;
    STACKinit(choose_number);
    STACKpush(createlist(choose_number));
    int c = 1;
    while (!STACKempty()) {
        head = STACKpop();
        printf("%d", c);
        printList(head.ptr_list);
        createsum(head.ptr_list);
        c++;
        free_list(head.ptr_list);
    }
    freeStack();
    return 0;
}
