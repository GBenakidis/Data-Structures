# Dictionary

## Overview
This C code is a comprehensive dictionary application designed to efficiently search for and retrieve word meanings. It employs two different strategies for optimizing word lookups. The first approach employs separate chaining in a hash table, ensuring efficient word storage and retrieval with minimal collisions. The second method leverages the QuickSort algorithm to sort words and store them in an array of structures, significantly enhancing search performance. Both strategies utilize a prime multiplier-based hashing technique for effective word indexing and collision prevention. The program features a user-friendly interface for word searches, dynamic memory management, input validation, and the ability to read from a dictionary file.

## Features
- Efficient word search and retrieval.
- Two different strategies for word storage and retrieval.
- Hash table with separate chaining for optimized storage.
- QuickSort algorithm for sorting and faster search.
- User-friendly interface for word lookups.
- Dynamic memory management.
- Input validation and error handling.

## Data Structures

In the provided C code, two main data structures are used:

1. **Hash Table with Separate Chaining**: The first data structure used is a hash table. A hash table is an array-based data structure that allows for efficient storage and retrieval of key-value pairs. In this code, it's used to store words, where the word is the key and its associated data (or meanings) is the value. To handle collisions (i.e., when two words hash to the same location), a technique called "separate chaining" is employed. Separate chaining involves maintaining linked lists at each hash table entry to handle collisions by chaining elements with the same hash.

2. **Structures**: In C, structures are user-defined data types that allow bundling multiple variables of different data types under a single name. In this code, a custom structure named `Item` is defined. The `Item` structure contains two fields: a character pointer (`str`) to store a sorted word and a pointer to a linked list (`chain`) of unsorted words. These structures are used to store and manage sorted and unsorted words efficiently.

The code also employs arrays, character arrays (strings), and dynamically allocated memory using `malloc` to manage and manipulate data efficiently. Additionally, the code uses arrays and pointers to manage the hash table and linked lists for separate chaining.

Overall, these data structures and techniques enable efficient word storage, retrieval, and management in the dictionary application.

## Functions
Certainly, here's a brief description of each function in the provided code:

1. `insertAtEndAndReturnStart`: This function inserts a word at the end of a linked list and returns the updated start of the list. It's used to build linked lists of unsorted words for words that hash to the same location in the hash table.

2. `isPrime`: This simple function checks if a given integer is a prime number. It's used to find a prime number close to a specified value to determine the hash table size.

3. `bigFreeArr`: This function frees memory allocated for an array of `Item` structures, including both sorted words and associated linked lists of unsorted words. It ensures all memory is properly deallocated.

4. `freeList`: Given a linked list of words, this function frees all the allocated memory for the words and nodes in the list.

5. `freeArr`: This function is used to free memory allocated for an array of character pointers (strings).

6. `calculateStringHash`: Calculates the hash value of a given string using a simple hashing algorithm. It's used to map words to specific locations in the hash table.

7. `QuickSort`: A standard implementation of the QuickSort algorithm, used to sort characters in a word. It's used to prepare words for hashing and comparison.

8. `secondQuestion`: The core of the second part of the code, it initializes a hash table with sorted words, reads and hashes words from a dictionary file, and allows users to search for words. If found, it prints the words and their meanings. If not found, it indicates that the word is not in the dictionary.

9. `insertIntoHashTable`: This function hashes a word and inserts it into the hash table. It's called when building the dictionary's hash table.

10. `firstQuestion`: The core of the first part of the code, it initializes a hash table, reads words from a dictionary file, and allows users to search for a word in the dictionary. If the word is found, it prints a message indicating the word was found. If not found, it indicates that the word is not in the dictionary.

11. `main`: The main function that controls the execution of both "firstQuestion" and "secondQuestion." It calls these functions in sequence to perform dictionary operations.

Each of these functions serves a specific purpose in managing and searching a dictionary, with some functions focused on memory management, others on sorting and hashing, and the core functions dealing with dictionary functionality.

## Program Flow

The program's flow involves the following key steps:

1. **Initialization**:
   - The program starts by defining several constants and data structures for managing the dictionary. This includes setting the dictionary size, table size, and defining data structures such as WordNode and Item for managing words and their hash table entries.

2. **Data Structure Initialization**:
   - In both parts of the code (firstQuestion and secondQuestion), data structures for managing the dictionary are initialized. This includes initializing an array of linked lists (hashTable) and dynamic arrays for storing dictionary words.

3. **Reading Dictionary Data**:
   - In the first part of the code (firstQuestion), the program reads words from a dictionary file and inserts them into the hash table using the "insertIntoHashTable" function. These words are stored in linked lists within the hash table to allow efficient retrieval.

4. **User Interaction - Part 1 (firstQuestion)**:
   - The program interacts with the user, asking for input. It prompts the user to provide a word they want to look up in the dictionary. The user's input is validated, ensuring it's within the defined bounds (0 to 183,719), and then the program proceeds to search for the word.

5. **Hashing and Search - Part 1 (firstQuestion)**:
   - The program hashes the user's input using the "calculateStringHash" function to determine the location in the hash table. It then searches through the linked list at that location for the requested word. If found, it prints a message indicating that the word was found. If not found, it indicates that the word is not in the dictionary.

6. **User Interaction - Part 2 (secondQuestion)**:
   - In the second part of the code (secondQuestion), the program interacts with the user similarly. It prompts the user to provide a word they want to look up in the dictionary, and the user's input is validated.

7. **Hashing and Search - Part 2 (secondQuestion)**:
   - The program hashes the user's input, just like in the first part, and searches for the word in the sorted words array. If found, it prints the word's meaning (associated unsorted words). If not found, it indicates that the word is not in the dictionary.

8. **Freeing Memory**:
   - After the search is complete in both parts, the program proceeds to free any dynamically allocated memory. In particular, memory used for the hash table, linked lists, and dynamically allocated character arrays is freed.

9. **Program Termination**:
   - The program concludes, returning to the operating system with an exit status.

The program's main functionality revolves around reading and searching a dictionary of words. It uses a combination of hash tables and sorting techniques to efficiently search and retrieve word meanings. User interaction is a fundamental part of this process, as the program prompts users to provide words they want to look up in the dictionary.

The flow ensures that memory is allocated and deallocated appropriately to avoid memory leaks, and it maintains the integrity of the dictionary data structures.

## Examples

**Example Interaction with "firstQuestion"**:
```
Give me the Dictionary size (0, 183719): 5
Please Give me Word: apple
Found: apple

Give me the Dictionary size (0, 183719): 5
Please Give me Word: orange
Word not found
```

In this interaction with "firstQuestion," the user is asked to provide a dictionary size between 0 and 183,719. In this example, we chose 5. Then, the user is prompted to enter a word to search. When "apple" is entered, the program finds it in the dictionary. However, when "orange" is entered, it's not found in the dictionary.

**Example Interaction with "secondQuestion"**:
```
Please Give me Word: cinema
Word not found

Please Give me Word: listen
Found words with the same letters: silent
```

In the "secondQuestion" part, the user is asked for a word to search for anagrams. When "cinema" is entered, it's not found in the dictionary. But when "listen" is entered, the program finds the word "silent" as an anagram and displays it.
