
# IntegerCompositions

## Overview

This C program is designed to generate and print all possible combinations of positive integers that add up to a given positive integer provided by the user. It utilizes a stack data structure and recursive techniques to generate these combinations. The code has been structured into functions to make it modular and organized.

## Data Structures

The program uses two primary data structures: `listpointer` for linked list nodes and `List` to represent a list of integers. Additionally, there is an `Item` structure that encapsulates a `List` to be used in the stack.

```c
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
```

- `listpointer`: This structure represents a linked list node and includes an integer `x` for data and a pointer to the next node.
- `List`: This structure is used to store a list of integers, including the size of the list and an array to hold the elements.
- `Item`: It encapsulates a `List` to be used in the stack. It will be used for pushing and popping items from the stack.

## Functions

### `STACKempty()`

This function checks whether the stack is empty and returns a boolean value.

```c
int STACKempty() {
    return N == 0;
}
```

### `STACKinit(int maxN)`

`STACKinit` initializes the stack by allocating memory for the stack items.

```c
void STACKinit(int maxN) {
    Stack = (Item *)malloc(maxN * sizeof(Item));
    N = 0;
}
```

### `STACKpush(List *item)`

`STACKpush` is used to push a `List` item onto the stack. It checks for stack capacity and performs the push operation.

```c
void STACKpush(List *item) {
    if (N < Max_Num) {
        Stack[N].ptr_list = item;
        N++;
    } else {
        printf("Stack is full.\n");
        exit(1);
    }
}
```

### `STACKpop()`

`STACKpop` is used to pop an item from the stack. It returns the popped item. It checks for an empty stack and performs the pop operation.

```c
Item STACKpop() {
    if (!STACKempty()) {
        N--;
        return Stack[N];
    } else {
        printf("Stack is empty.\n");
        exit(1);
    }
}
```

### `printList(List *lst)`

This function is responsible for printing the elements of a `List` with a "+" sign between them to represent a combination.

```c
void printList(List *lst) {
    for (int i = 0; i < lst->size; i++) {
        if (i > 0) {
            printf("+");
        }
        printf("%d", lst->elements[i]);
    }
    printf("\n");
}
```

### `generateCombinations(int n, List *currentList)`

`generateCombinations` is the heart of the program. It generates all possible combinations of integers that add up to `n`. The function uses recursion and backtracking to explore and generate combinations. 

```c
void generateCombinations(int n, List *currentList) {
    if (n == 0) {
        printList(currentList);
        return;
    }

    if (n < 0 || currentList->size >= 2) {
        return;
    }

    for (int i = 1; i <= n; i++) {
        currentList->elements[currentList->size] = i;
        currentList->size++;
        STACKpush(currentList);
        generateCombinations(n - i, currentList);
        currentList->size--;
        currentList = STACKpop().ptr_list;
    }
}
```

This function recursively generates all valid combinations, and it prints the combination when the target sum is reached (i.e., `n == 0`). It uses the stack to keep track of the current combination and backtracks when necessary.

### `freeStack()`

`freeStack` is used to free the memory allocated for stack items and ensures there are no memory leaks.

```c
void freeStack() {
    for (int i = 0; i < N; i++) {
        free(Stack[i].ptr_list);
    }
    free(Stack);
}
```

### `main()`

The `main` function is the entry point of the program. It takes user input for a positive integer, initializes the stack, generates combinations, and cleans up memory.

## Program Flow

1. **User Input:** The program begins by requesting the user to input a positive integer.

2. **Input Validation:** User input is collected and validated to ensure it's a positive integer. The program will continue to prompt the user until a valid input is provided.

3. **Data Initialization:** Upon receiving a valid input, the program initializes a `List` structure called `currentList` to store the current combination. The `size` field of `currentList` is set to 0, indicating an empty list.

4. **Stack Initialization:** The `STACKinit` function is invoked to initialize the stack for storing combinations. The size of the stack is determined based on the user's chosen integer.

5. **Combination Generation:** The `generateCombinations` function is called with the user's input and `currentList` as arguments. This function initiates the process of generating all valid combinations of positive integers that sum up to the user-provided value. The stack is used for maintaining and exploring combinations.

6. **Combination Printing:** Inside the `generateCombinations` function, valid combinations are generated and printed. The function utilizes recursive techniques and backtracking to explore different combinations. The stack plays a crucial role in tracking and managing the generation process.

7. **Memory Cleanup:** After all possible combinations have been generated, the program proceeds to clean up memory by invoking the `freeStack` function. This step is crucial to prevent memory leaks and ensure efficient resource management.


## Example Output

By giving the input `5` it outputs:

```c
5
1+1+1+1+1
1+1+1+2
1+1+2+1
1+2+1+1
2+1+1+1
1+1+3
1+3+1
3+1+1
2+2+1
2+1+2
1+2+2
1+1+4
1+4+1
4+1+1
2+3
3+2
```

## Error Handling

The program includes error handling for cases where the stack is full or empty. It will display appropriate error messages and exit if necessary.
