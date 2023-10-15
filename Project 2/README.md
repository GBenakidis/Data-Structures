# GrayCode Encode and Decode

## Overview

This C project implements a binary tree-based text encoding and decoding system. The core functionality includes constructing binary trees, encoding text messages, and decoding encoded messages. The project is structured into several files for modularity. main.c contains the primary program logic, node.c handles binary tree structures, gray_tree.c manages Gray code-based tree operations, and encode.c deals with message encoding and decoding. This project offers a user-friendly interface for encoding, decoding, and tree exploration. It provides a foundation for understanding and working with binary tree-based encoding techniques.

## Data Structures

The project primarily revolves around a binary tree data structure. This binary tree, represented by the `link` structure, is a fundamental component of the encoding and decoding process. It consists of three main fields:

1. `char* data`: This field holds character data corresponding to the binary path to the node in the tree. For encoding, this data represents the binary code, while for decoding, it serves as a mapping to ASCII characters.

2. `struct TreeNode* l`: This field points to the left subtree of the current node. It is essential for constructing binary trees during the generation of Gray codes and plays a pivotal role in the encoding and decoding process.

3. `struct TreeNode* r`: Similar to the left subtree, this field points to the right subtree of the current node. It is used for building binary tree structures during Gray code generation and assists in encoding and decoding text messages.

The binary tree data structure allows for efficient traversal and mapping of binary codes to corresponding ASCII characters during encoding and vice versa during decoding. It's the backbone of the project, enabling the conversion of text messages into binary codes and their subsequent retrieval.

## Functions

The `encode.c` file contains two key functions for encoding and decoding messages using a binary tree. Here's a detailed analysis of these functions:

1. **EncodeString:**
   - `EncodeString` takes a binary tree `root` and a string `str` as input.
   - It opens a file "Decoded.txt" for writing. If the file cannot be opened, it displays an error message, destroys the binary tree `root`, and exits the program.
   - The function then proceeds to encode the input string `str` into binary code by traversing the binary tree. It follows the path in the tree corresponding to each character in the string and converts it to a binary code.
   - The encoded binary code is then written to the "Decoded.txt" file.
   - During the encoding process, it also displays the encoded character to the console.
   - Finally, it closes the output file.

2. **DecodeString:**
   - `DecodeString` takes a binary tree `root` as input.
   - It opens a file "Encoded.txt" for reading. If the file cannot be opened, it displays an error message, destroys the binary tree `root`, and exits the program.
   - The function proceeds to decode the binary code from the input file by traversing the binary tree `root`. It reads binary codes from the file and follows the tree path to identify the corresponding characters.
   - Decoded characters are displayed to the console during the decoding process.
   - The function reads one character at a time from the input file and decodes it, repeating the process until there are no more characters to decode.
   - It also frees memory allocated for `ptr` after decoding each character.
   - Finally, it closes the input file.

3. **charToBinary:**
   - `charToBinary` is a utility function that converts an unsigned character `n` into an 8-character binary string. For example, it converts the integer 97 (ASCII code for 'a') into the binary string "01100001."
   - It allocates memory for the binary string, converts the integer into binary format, and null-terminates the string.
   - The function then returns a pointer to the binary string.

These functions work together to encode and decode messages using a binary tree structure. `EncodeString` encodes a given string and stores it in an output file, while `DecodeString` reads an encoded message from an input file, decodes it using the binary tree, and displays the original message. `charToBinary` is a utility function used during the encoding and decoding processes to convert characters to binary representation.

**Overview:**

This GitHub repository contains a collection of C files for encoding, decoding, and manipulating binary trees. The primary purpose of these files is to demonstrate encoding and decoding messages using a binary tree structure, as well as other tree-related functions.

**Function Analysis:**

1. **main.c:**
   - `main`: This function is the entry point of the program. It demonstrates the encoding and decoding process using binary trees. It also allows the user to create and print Gray trees of various sizes.
   - Input: User provides a message and the size of the Gray tree to create.
   - Output: Encoded and decoded messages, and a printed Gray tree.

2. **node.c:**
   - `CreateTree`: Creates a binary tree of a specified height, where each node is initialized as a copy of the left subtree, and leaf nodes are NULL.
   - Input: Height of the tree.
   - Output: The root of the binary tree.
   - `DestroyTree`: Recursively destroys the binary tree and deallocates memory.
   - Input: The root of the binary tree to destroy.
   - Output: Memory deallocated.

3. **gray_tree.c:**
   - `SimpleGrayTree`: Initializes a binary tree as a simple Gray code tree. It assigns '0' and '1' data values to left and right subtrees, respectively.
   - Input: The root of the tree to initialize and the height of the tree.
   - Output: The root of the initialized Gray code tree.
   - `DuplicateTree`: Duplicates a binary tree with two identical subtrees with '0' and '1' data values.
   - Input: The root of the original tree, the root of the new subtree, and the height of the tree.
   - Output: Duplicated binary tree with modified data values.

4. **printing.c:**
   - `PrintTree`: Recursively prints the binary tree's data values, level-wise.
   - Input: The root of the binary tree and the height of the tree.
   - Output: Tree data printed to the console.

The `charToBinary` function is not included in the analysis, as it is declared within the `encoding.c` file but is a common utility used for converting characters to binary representation.

**Note:** The program is designed to encode and decode messages using a binary tree structure and to create and print Gray trees. These functions are interrelated, allowing the program to showcase various tree operations, encoding, and decoding processes.

## Program Flow

The program's flow is as follows:

1. **Binary Tree Creation (`CreateTree` in `node.c`):** The program starts by creating a binary tree structure using the `CreateTree` function. The user specifies the height of the tree, which determines the depth and complexity of the tree.

2. **Ascii-to-Gray Code Mapping (`PopulateAscii` in `gray_tree.c`):** The program reads mappings from an external file, `BinarytoGray.txt`, to populate the tree with ASCII-to-Gray code mappings. It does so by traversing the tree based on the Gray code sequence.

3. **User Input Message (`main` in `main.c`):** The user is prompted to input a message that they want to encode. The program reads this user input.

4. **Message Encoding (`EncodeString` in `encode.c`):** The program encodes the user's message into a binary format. It processes each character of the message, traverses the binary tree based on the character's binary representation, and writes the encoded message to an external file, `Encoded.txt`.

5. **Gray-to-Ascii Code Mapping (`PopulateGrey` in `gray_tree.c`):** The program again reads mappings from an external file, `BinarytoGray.txt`, but this time it populates the tree with Gray-to-ASCII code mappings.

6. **Message Decoding (`DecodeString` in `encode.c`):** The program decodes the message from `Encoded.txt` back to its original ASCII form. It reads the binary-encoded message, traverses the tree, and decodes it character by character. The decoded message is displayed in the terminal.

7. **User Input for Gray Tree Size (`main` in `main.c`):** The user is prompted to specify the size of the Gray tree they want to create.

8. **Gray Tree Generation (`main` in `main.c`):** The program generates a Gray tree based on the user's choice. It does so by iteratively duplicating the tree structure and connecting it in a specific way to create a new Gray tree.

9. **Print Gray Tree (`PrintTree` in `encode.c`):** The final Gray tree structure is printed to the terminal for the user to see.

10. **Cleanup (`DestroyTree` in `node.c`):** The memory allocated for the binary tree structures is freed to prevent memory leaks. This cleanup step is crucial for efficient memory management.

The program primarily focuses on encoding and decoding messages using a binary tree and allows users to explore the structure of Gray trees. The mappings from ASCII to Gray codes and vice versa are essential for these encoding and decoding processes.

## Example Overview Input-Output
Certainly, let's walk through a simple example of how the program works. For this example, we'll use a smaller tree with a height of 2 to keep things manageable.

**1. Binary Tree Creation (`CreateTree` in `node.c`):** We start by creating a binary tree with a height of 2. The tree structure might look something like this:

```
       Root
      /    \
    NULL   NULL
```

**2. Ascii-to-Gray Code Mapping (`PopulateAscii` in `gray_tree.c`):** The program reads mappings from an external file, `BinarytoGray.txt`, to populate the tree with ASCII-to-Gray code mappings. Let's say the mappings look like this:

```
ASCII    : Gray
A        : 010
B        : 110
```

The program will traverse the binary tree based on the Gray code sequences and map ASCII characters to Gray codes:

```
       Root
      /    \
    NULL   NULL
    / \     / \
   A   B  NULL  NULL
  010  110
```

**3. User Input Message (`main` in `main.c`):** The user is prompted to input a message. Let's say the user enters the message "AB."

**4. Message Encoding (`EncodeString` in `encode.c`):** The program encodes the user's message into a binary format. It processes each character of the message, traverses the binary tree, and writes the encoded message to an external file, `Encoded.txt`.

For the message "AB," the encoded output might be: `010110`

**5. Gray-to-Ascii Code Mapping (`PopulateGrey` in `gray_tree.c`):** The program reads mappings from an external file, `BinarytoGray.txt`, but this time it populates the tree with Gray-to-ASCII code mappings. The same tree structure created earlier is now used to map Gray codes back to ASCII characters:

```
       Root
      /    \
    NULL   NULL
    / \     / \
   A   B   NULL  NULL
  010  110
```

**6. Message Decoding (`DecodeString` in `encode.c`):** The program decodes the message from `Encoded.txt` back to its original ASCII form. It reads the binary-encoded message (`010110`), traverses the tree, and decodes it character by character. The decoded message is displayed in the terminal.

The decoded message for `010110` is "AB."

**7. User Input for Gray Tree Size (`main` in `main.c`):** The user is prompted to specify the size of the Gray tree they want to create. Let's say the user chooses a size of 2.

**8. Gray Tree Generation (`main` in `main.c`):** The program generates a Gray tree based on the user's choice. It creates a new Gray tree structure by duplicating the existing tree and connecting it in a specific way. For a size of 2, the structure might look like this:

```
        New Root
       /     \
    Previous  Copy of Previous
    Gray Tree Gray Tree
```

**9. Print Gray Tree (`PrintTree` in `encode.c`):** The final Gray tree structure is printed to the terminal for the user to see. The structure of the newly created Gray tree is displayed.

**10. Cleanup (`DestroyTree` in `node.c`):** The memory allocated for the binary tree structures is freed to prevent memory leaks, ensuring efficient memory management.

This example illustrates the basic operation of the program, focusing on encoding and decoding messages and the creation of Gray trees. The specific ASCII-to-Gray and Gray-to-ASCII mappings determine the encoding and decoding process.